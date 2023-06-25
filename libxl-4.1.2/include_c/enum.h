///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//                    LibXL C++ headers version 4.1.2                        //
//                                                                           //
//                 Copyright (c) 2008 - 2023 XLware s.r.o.                   //
//                                                                           //
//   THIS FILE AND THE SOFTWARE CONTAINED HEREIN IS PROVIDED 'AS IS' AND     //
//                COMES WITH NO WARRANTIES OF ANY KIND.                      //
//                                                                           //
//          Please define LIBXL_STATIC variable for static linking.          //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#ifndef LIBXL_ENUM_C_H
#define LIBXL_ENUM_C_H

enum Color {COLOR_BLACK = 8, COLOR_WHITE, COLOR_RED, COLOR_BRIGHTGREEN, COLOR_BLUE, COLOR_YELLOW, COLOR_PINK, COLOR_TURQUOISE, COLOR_DARKRED,
            COLOR_GREEN, COLOR_DARKBLUE, COLOR_DARKYELLOW, COLOR_VIOLET, COLOR_TEAL, COLOR_GRAY25, COLOR_GRAY50, COLOR_PERIWINKLE_CF,
            COLOR_PLUM_CF, COLOR_IVORY_CF, COLOR_LIGHTTURQUOISE_CF, COLOR_DARKPURPLE_CF, COLOR_CORAL_CF, COLOR_OCEANBLUE_CF, COLOR_ICEBLUE_CF,
            COLOR_DARKBLUE_CL, COLOR_PINK_CL, COLOR_YELLOW_CL, COLOR_TURQUOISE_CL, COLOR_VIOLET_CL, COLOR_DARKRED_CL, COLOR_TEAL_CL,
            COLOR_BLUE_CL, COLOR_SKYBLUE, COLOR_LIGHTTURQUOISE, COLOR_LIGHTGREEN, COLOR_LIGHTYELLOW, COLOR_PALEBLUE, COLOR_ROSE, COLOR_LAVENDER,
            COLOR_TAN, COLOR_LIGHTBLUE, COLOR_AQUA, COLOR_LIME, COLOR_GOLD, COLOR_LIGHTORANGE, COLOR_ORANGE, COLOR_BLUEGRAY, COLOR_GRAY40,
            COLOR_DARKTEAL, COLOR_SEAGREEN, COLOR_DARKGREEN, COLOR_OLIVEGREEN, COLOR_BROWN, COLOR_PLUM, COLOR_INDIGO, COLOR_GRAY80,
            COLOR_DEFAULT_FOREGROUND = 0x0040, COLOR_DEFAULT_BACKGROUND = 0x0041, COLOR_TOOLTIP = 0x0051, COLOR_NONE = 0x7F, COLOR_AUTO = 0x7FFF};

enum NumFormat {NUMFORMAT_GENERAL, NUMFORMAT_NUMBER, NUMFORMAT_NUMBER_D2, NUMFORMAT_NUMBER_SEP, NUMFORMAT_NUMBER_SEP_D2,
                NUMFORMAT_CURRENCY_NEGBRA, NUMFORMAT_CURRENCY_NEGBRARED, NUMFORMAT_CURRENCY_D2_NEGBRA, NUMFORMAT_CURRENCY_D2_NEGBRARED,
                NUMFORMAT_PERCENT, NUMFORMAT_PERCENT_D2, NUMFORMAT_SCIENTIFIC_D2, NUMFORMAT_FRACTION_ONEDIG, NUMFORMAT_FRACTION_TWODIG,
                NUMFORMAT_DATE, NUMFORMAT_CUSTOM_D_MON_YY, NUMFORMAT_CUSTOM_D_MON, NUMFORMAT_CUSTOM_MON_YY,
                NUMFORMAT_CUSTOM_HMM_AM, NUMFORMAT_CUSTOM_HMMSS_AM, NUMFORMAT_CUSTOM_HMM, NUMFORMAT_CUSTOM_HMMSS,
                NUMFORMAT_CUSTOM_MDYYYY_HMM,
                NUMFORMAT_NUMBER_SEP_NEGBRA = 37, NUMFORMAT_NUMBER_SEP_NEGBRARED,
                NUMFORMAT_NUMBER_D2_SEP_NEGBRA, NUMFORMAT_NUMBER_D2_SEP_NEGBRARED, NUMFORMAT_ACCOUNT, NUMFORMAT_ACCOUNTCUR,
                NUMFORMAT_ACCOUNT_D2, NUMFORMAT_ACCOUNT_D2_CUR, NUMFORMAT_CUSTOM_MMSS, NUMFORMAT_CUSTOM_H0MMSS,
                NUMFORMAT_CUSTOM_MMSS0, NUMFORMAT_CUSTOM_000P0E_PLUS0, NUMFORMAT_TEXT};

enum AlignH {ALIGNH_GENERAL, ALIGNH_LEFT, ALIGNH_CENTER, ALIGNH_RIGHT, ALIGNH_FILL, ALIGNH_JUSTIFY, ALIGNH_MERGE, ALIGNH_DISTRIBUTED};
enum AlignV {ALIGNV_TOP, ALIGNV_CENTER, ALIGNV_BOTTOM, ALIGNV_JUSTIFY, ALIGNV_DISTRIBUTED};

enum BorderStyle {BORDERSTYLE_NONE, BORDERSTYLE_THIN, BORDERSTYLE_MEDIUM, BORDERSTYLE_DASHED, BORDERSTYLE_DOTTED, BORDERSTYLE_THICK,
                  BORDERSTYLE_DOUBLE, BORDERSTYLE_HAIR, BORDERSTYLE_MEDIUMDASHED, BORDERSTYLE_DASHDOT, BORDERSTYLE_MEDIUMDASHDOT,
                  BORDERSTYLE_DASHDOTDOT, BORDERSTYLE_MEDIUMDASHDOTDOT, BORDERSTYLE_SLANTDASHDOT};

enum BorderDiagonal {BORDERDIAGONAL_NONE, BORDERDIAGONAL_DOWN, BORDERDIAGONAL_UP, BORDERDIAGONAL_BOTH};

enum FillPattern {FILLPATTERN_NONE, FILLPATTERN_SOLID, FILLPATTERN_GRAY50, FILLPATTERN_GRAY75, FILLPATTERN_GRAY25,
                  FILLPATTERN_HORSTRIPE, FILLPATTERN_VERSTRIPE, FILLPATTERN_REVDIAGSTRIPE, FILLPATTERN_DIAGSTRIPE,
                  FILLPATTERN_DIAGCROSSHATCH, FILLPATTERN_THICKDIAGCROSSHATCH, FILLPATTERN_THINHORSTRIPE, FILLPATTERN_THINVERSTRIPE,
                  FILLPATTERN_THINREVDIAGSTRIPE, FILLPATTERN_THINDIAGSTRIPE, FILLPATTERN_THINHORCROSSHATCH, FILLPATTERN_THINDIAGCROSSHATCH,
                  FILLPATTERN_GRAY12P5, FILLPATTERN_GRAY6P25};

enum Script {SCRIPT_NORMAL, SCRIPT_SUPER, SCRIPT_SUB};
enum Underline {UNDERLINE_NONE, UNDERLINE_SINGLE, UNDERLINE_DOUBLE, UNDERLINE_SINGLEACC = 0x21, UNDERLINE_DOUBLEACC = 0x22};

enum Paper {PAPER_DEFAULT, PAPER_LETTER, PAPER_LETTERSMALL, PAPER_TABLOID, PAPER_LEDGER, PAPER_LEGAL, PAPER_STATEMENT, PAPER_EXECUTIVE, PAPER_A3,
            PAPER_A4, PAPER_A4SMALL, PAPER_A5, PAPER_B4, PAPER_B5, PAPER_FOLIO, PAPER_QUATRO, PAPER_10x14, PAPER_10x17, PAPER_NOTE, PAPER_ENVELOPE_9,
            PAPER_ENVELOPE_10, PAPER_ENVELOPE_11, PAPER_ENVELOPE_12, PAPER_ENVELOPE_14, PAPER_C_SIZE, PAPER_D_SIZE, PAPER_E_SIZE, PAPER_ENVELOPE_DL,
            PAPER_ENVELOPE_C5, PAPER_ENVELOPE_C3, PAPER_ENVELOPE_C4, PAPER_ENVELOPE_C6, PAPER_ENVELOPE_C65, PAPER_ENVELOPE_B4, PAPER_ENVELOPE_B5,
            PAPER_ENVELOPE_B6, PAPER_ENVELOPE, PAPER_ENVELOPE_MONARCH, PAPER_US_ENVELOPE, PAPER_FANFOLD, PAPER_GERMAN_STD_FANFOLD,
            PAPER_GERMAN_LEGAL_FANFOLD, PAPER_B4_ISO, PAPER_JAPANESE_POSTCARD, PAPER_9x11, PAPER_10x11, PAPER_15x11, PAPER_ENVELOPE_INVITE,
            PAPER_US_LETTER_EXTRA = 50, PAPER_US_LEGAL_EXTRA, PAPER_US_TABLOID_EXTRA, PAPER_A4_EXTRA, PAPER_LETTER_TRANSVERSE, PAPER_A4_TRANSVERSE,
            PAPER_LETTER_EXTRA_TRANSVERSE, PAPER_SUPERA, PAPER_SUPERB, PAPER_US_LETTER_PLUS, PAPER_A4_PLUS, PAPER_A5_TRANSVERSE, PAPER_B5_TRANSVERSE,
            PAPER_A3_EXTRA, PAPER_A5_EXTRA, PAPER_B5_EXTRA, PAPER_A2, PAPER_A3_TRANSVERSE, PAPER_A3_EXTRA_TRANSVERSE, PAPER_JAPANESE_DOUBLE_POSTCARD,
            PAPER_A6, PAPER_JAPANESE_ENVELOPE_KAKU2, PAPER_JAPANESE_ENVELOPE_KAKU3, PAPER_JAPANESE_ENVELOPE_CHOU3, PAPER_JAPANESE_ENVELOPE_CHOU4,
            PAPER_LETTER_ROTATED, PAPER_A3_ROTATED, PAPER_A4_ROTATED, PAPER_A5_ROTATED, PAPER_B4_ROTATED, PAPER_B5_ROTATED,
            PAPER_JAPANESE_POSTCARD_ROTATED, PAPER_DOUBLE_JAPANESE_POSTCARD_ROTATED, PAPER_A6_ROTATED, PAPER_JAPANESE_ENVELOPE_KAKU2_ROTATED,
            PAPER_JAPANESE_ENVELOPE_KAKU3_ROTATED, PAPER_JAPANESE_ENVELOPE_CHOU3_ROTATED, PAPER_JAPANESE_ENVELOPE_CHOU4_ROTATED, PAPER_B6,
            PAPER_B6_ROTATED, PAPER_12x11, PAPER_JAPANESE_ENVELOPE_YOU4, PAPER_JAPANESE_ENVELOPE_YOU4_ROTATED, PAPER_PRC16K, PAPER_PRC32K,
            PAPER_PRC32K_BIG, PAPER_PRC_ENVELOPE1, PAPER_PRC_ENVELOPE2, PAPER_PRC_ENVELOPE3, PAPER_PRC_ENVELOPE4, PAPER_PRC_ENVELOPE5,
            PAPER_PRC_ENVELOPE6, PAPER_PRC_ENVELOPE7, PAPER_PRC_ENVELOPE8, PAPER_PRC_ENVELOPE9, PAPER_PRC_ENVELOPE10, PAPER_PRC16K_ROTATED,
            PAPER_PRC32K_ROTATED, PAPER_PRC32KBIG_ROTATED, PAPER_PRC_ENVELOPE1_ROTATED, PAPER_PRC_ENVELOPE2_ROTATED, PAPER_PRC_ENVELOPE3_ROTATED,
            PAPER_PRC_ENVELOPE4_ROTATED, PAPER_PRC_ENVELOPE5_ROTATED, PAPER_PRC_ENVELOPE6_ROTATED, PAPER_PRC_ENVELOPE7_ROTATED,
            PAPER_PRC_ENVELOPE8_ROTATED, PAPER_PRC_ENVELOPE9_ROTATED, PAPER_PRC_ENVELOPE10_ROTATED};

enum SheetType { SHEETTYPE_SHEET, SHEETTYPE_CHART, SHEETTYPE_UNKNOWN };

enum CellType {CELLTYPE_EMPTY, CELLTYPE_NUMBER, CELLTYPE_STRING, CELLTYPE_BOOLEAN, CELLTYPE_BLANK, CELLTYPE_ERROR, CELLTYPE_STRICTDATE};

enum ErrorType {ERRORTYPE_NULL = 0x00, ERRORTYPE_DIV_0 = 0x07, ERRORTYPE_VALUE = 0x0F, ERRORTYPE_REF = 0x17, ERRORTYPE_NAME = 0x1D,
                ERRORTYPE_NUM = 0x24, ERRORTYPE_NA = 0x2A, ERRORTYPE_NOERROR = 0xFF};

enum PictureType {PICTURETYPE_PNG, PICTURETYPE_JPEG, PICTURETYPE_GIF, PICTURETYPE_WMF, PICTURETYPE_DIB, PICTURETYPE_EMF,
                  PICTURETYPE_PICT, PICTURETYPE_TIFF, PICTURETYPE_ERROR = 0xFF};

enum SheetState {SHEETSTATE_VISIBLE, SHEETSTATE_HIDDEN, SHEETSTATE_VERYHIDDEN};

enum Scope {SCOPE_UNDEFINED = -2, SCOPE_WORKBOOK = -1};

enum Position {POSITION_MOVE_AND_SIZE, POSITION_ONLY_MOVE, POSITION_ABSOLUTE};

enum Operator { OPERATOR_EQUAL, OPERATOR_GREATER_THAN, OPERATOR_GREATER_THAN_OR_EQUAL, OPERATOR_LESS_THAN, OPERATOR_LESS_THAN_OR_EQUAL, OPERATOR_NOT_EQUAL };

enum Filter { FILTER_VALUE, FILTER_TOP10, FILTER_CUSTOM, FILTER_DYNAMIC, FILTER_COLOR, FILTER_ICON, FILTER_EXT, FILTER_NOT_SET };

enum IgnoredError { IERR_NO_ERROR = 0, IERR_EVAL_ERROR = 1, IERR_EMPTY_CELLREF = 2, IERR_NUMBER_STORED_AS_TEXT = 4, IERR_INCONSIST_RANGE = 8,
                    IERR_INCONSIST_FMLA = 16, IERR_TWODIG_TEXTYEAR = 32, IERR_UNLOCK_FMLA = 64, IERR_DATA_VALIDATION = 128 };

enum EnhancedProtection { PROT_DEFAULT = -1, PROT_ALL = 0, PROT_OBJECTS = 1, PROT_SCENARIOS = 2, PROT_FORMAT_CELLS = 4, PROT_FORMAT_COLUMNS = 8, PROT_FORMAT_ROWS = 16,
                          PROT_INSERT_COLUMNS = 32, PROT_INSERT_ROWS = 64, PROT_INSERT_HYPERLINKS = 128, PROT_DELETE_COLUMNS = 256, PROT_DELETE_ROWS = 512,
                          PROT_SEL_LOCKED_CELLS = 1024, PROT_SORT = 2048, PROT_AUTOFILTER = 4096, PROT_PIVOTTABLES = 8192, PROT_SEL_UNLOCKED_CELLS = 16384 };

enum DataValidationType { VALIDATION_TYPE_NONE, VALIDATION_TYPE_WHOLE, VALIDATION_TYPE_DECIMAL, VALIDATION_TYPE_LIST,
                          VALIDATION_TYPE_DATE, VALIDATION_TYPE_TIME, VALIDATION_TYPE_TEXTLENGTH, VALIDATION_TYPE_CUSTOM };

enum DataValidationOperator { VALIDATION_OP_BETWEEN, VALIDATION_OP_NOTBETWEEN, VALIDATION_OP_EQUAL, VALIDATION_OP_NOTEQUAL,
                              VALIDATION_OP_LESSTHAN, VALIDATION_OP_LESSTHANOREQUAL, VALIDATION_OP_GREATERTHAN, VALIDATION_OP_GREATERTHANOREQUAL };

enum DataValidationErrorStyle { VALIDATION_ERRSTYLE_STOP, VALIDATION_ERRSTYLE_WARNING, VALIDATION_ERRSTYLE_INFORMATION };

enum CalcModeType { CALCMODE_MANUAL, CALCMODE_AUTO, CALCMODE_AUTONOTABLE };

enum CheckedType { CHECKEDTYPE_UNCHECKED, CHECKEDTYPE_CHECKED, CHECKEDTYPE_MIXED };

enum ObjectType { OBJECT_UNKNOWN, OBJECT_BUTTON, OBJECT_CHECKBOX, OBJECT_DROP, OBJECT_GBOX, OBJECT_LABEL, OBJECT_LIST, OBJECT_RADIO, OBJECT_SCROLL, OBJECT_SPIN, OBJECT_EDITBOX, OBJECT_DIALOG };

enum CFormatType {
    CFORMAT_BEGINWITH, CFORMAT_CONTAINSBLANKS, CFORMAT_CONTAINSERRORS, CFORMAT_CONTAINSTEXT, CFORMAT_DUPLICATEVALUES, CFORMAT_ENDSWITH, CFORMAT_EXPRESSION,
    CFORMAT_NOTCONTAINSBLANKS, CFORMAT_NOTCONTAINSERRORS, CFORMAT_NOTCONTAINSTEXT, CFORMAT_UNIQUEVALUES
};

enum CFormatOperator {
    CFOPERATOR_LESSTHAN, CFOPERATOR_LESSTHANOREQUAL, CFOPERATOR_EQUAL, CFOPERATOR_NOTEQUAL, CFOPERATOR_GREATERTHANOREQUAL, CFOPERATOR_GREATERTHAN, CFOPERATOR_BETWEEN,
    CFOPERATOR_NOTBETWEEN, CFOPERATOR_CONTAINSTEXT, CFOPERATOR_NOTCONTAINS, CFOPERATOR_BEGINSWITH, CFOPERATOR_ENDSWITH
};


enum CFormatTimePeriod { CFTP_LAST7DAYS, CFTP_LASTMONTH, CFTP_LASTWEEK, CFTP_NEXTMONTH, CFTP_NEXTWEEK, CFTP_THISMONTH, CFTP_THISWEEK, CFTP_TODAY, CFTP_TOMORROW, CFTP_YESTERDAY };

enum CFVOType { CFVO_MIN, CFVO_MAX, CFVO_FORMULA, CFVO_NUMBER, CFVO_PERCENT, CFVO_PERCENTILE };

#endif
