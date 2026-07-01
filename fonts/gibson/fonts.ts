import { Platform } from "react-native";

const androidFonts = {
  bold: "Gibson-Bold",
  boldItalic: "Gibson-BoldItalic",
  italic: "Gibson-Italic",
  light: "Gibson-Light",
  lightItalic: "Gibson-LightIt",
  regular: "Gibson-Regular",
  semiBold: "Gibson-SemiBold",
  semiBoldItalic: "Gibson-SemiboldIt"
};
type FontType = Record<keyof typeof androidFonts, string>;

const iosFonts: FontType = { ...androidFonts };

const globalFonts =
  Platform.select({ android: androidFonts, ios: iosFonts }) || androidFonts;

export default globalFonts;

export type GlobalFontType = keyof typeof globalFonts;
