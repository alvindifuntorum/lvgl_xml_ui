# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## What This Project Is

This is an **LVGL XML UI project** created with the LVGL Editor. It defines a smart home HMI (Human-Machine Interface) dashboard with components like a thermostat, alarm, music player, weather, and more. The project targets embedded systems running LVGL.

### Local LVGL Reference

../lvgl/lvgl/docs
../lvgl/lvgl_editor/docs

## Build System

This project is consumed as a **CMake library** by a parent project (e.g., an ESP-IDF or simulator project) that provides LVGL as a dependency. It does not build standalone.

To integrate it:
```cmake
add_subdirectory(dome-hmi-ui)
target_link_libraries(your_app PRIVATE lib-ui)
```

To add your own `.c` files without touching generated files, append them in `user_config.cmake`.

## Architecture

### Code Generation Pattern

The editor generates `*_gen.c` / `*_gen.h` pairs from each XML file. **Never edit `*_gen.*` files** — they are overwritten when the editor re-generates. The non-generated counterparts (`examples.c`, component `.c` files without `_gen`) are safe to edit and are where custom logic goes.

- `globals.xml` → `examples_gen.c` / `examples_gen.h`: global consts, styles, subjects (reactive state), fonts, and images
- `examples.c` / `examples.h`: entry point; calls `examples_init_gen()` then allows custom post-init code
- `screens/elements.xml` → `screens/elements_gen.c`: the main screen layout
- `components/basic/*.xml` → `components/basic/*_gen.c`: reusable primitive widgets
- `components/cards/*.xml` → `components/cards/*_gen.c`: complex card-level components

### Reactive State (Subjects)

Global application state lives in `globals.xml` as `<subjects>`. Each subject becomes an `lv_subject_t` in `examples_gen.c`. Components bind to subjects via `bind_*` XML attributes (e.g., `bind_checked`, `bind_text`, `bind_value`, `bind_style`). To update state from code, call `lv_subject_set_int(&subject_name, value)`.

Current subjects and their meanings:
- `dark_theme` — `0` = light, `1` = dark; controls theme-switching across all components
- `thermostat_on/temp`, `room_temp` — thermostat state
- `alarm_on`, `alarm_hour`, `alarm_min` — alarm clock state
- `speaker`, `speaker_vol` — speaker on/off and volume
- `light_temperature`, `light_temperature_temp` — light bulb color temperature
- `song_played`, `song_liked`, `song_playing` — music player state
- `move_goal_target` — fitness move goal (0–2000)
- `location1_temp`, `location2_temp` — weather temperatures

### Design Tokens (Global Consts)

Colors, spacing, and opacity are defined in `globals.xml` under `<consts>`. In XML they are referenced with `#` prefix (e.g., `#accent1_light`). In generated C code they become uppercase macros (e.g., `ACCENT1_LIGHT`, `UNIT_MD`).

Spacing scale: `unit_sm=6`, `unit_md=12`, `unit_lg=18`, `unit_xl=24`.

Color variants follow the pattern `<name>_light` / `<name>_dark` for light/dark theme support.

### Fonts

All fonts use LVGL's TinyTTF (loaded from `.ttf` files at runtime via `asset_path`). Font names follow the pattern `<family>_<weight>_<size>` (e.g., `geist_semibold_28`). The `asset_path` string passed to `examples_init()` must point to the project root with a trailing slash so relative paths like `fonts/Geist/Geist-Regular.ttf` resolve correctly.

### Writing New Components

1. Create `components/<category>/<name>/<name>.xml` starting with `<component>`.
2. The editor generates `<name>_gen.c` / `<name>_gen.h`.
3. Use the component in screens or other components by its filename as the XML tag (e.g., `<thermostat />`).
4. API props defined in the XML `<api>` block become function parameters in the generated `_create()` function.

### Screens and Testing

Screens live in `screens/`. The main screen is `screens/elements.xml`. Test scenarios are XML files in `screens/tests/` using the `<test>` tag with `<steps>` (subject_set, screenshot_compare, move_to, press, release, wait). Reference screenshots for comparison are in `screens/tests/*.png`.
