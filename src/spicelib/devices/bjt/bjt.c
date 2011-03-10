/**********
Copyright 1990 Regents of the University of California.  All rights reserved.
Author: 1985 Thomas L. Quarles
**********/

/*
 * This file defines the BJT data structures that are
 * available to the next level(s) up the calling hierarchy
 */

/*
 * You may define the preprocessor symbolo
 * BJT_COMPAT to enable compatibility with
 * archaic spice2 bjt model
 */ 
 
#include "ngspice.h"
#include "devdefs.h"
#include "bjtdefs.h"
#include "suffix.h"

IFparm BJTpTable[] = { /* parameters */
 IOPU("off",     BJT_OFF,            IF_FLAG,    "Device initially off"),
 IOPAU("icvbe",  BJT_IC_VBE,         IF_REAL, "Initial B-E voltage"),
 IOPAU("icvce",  BJT_IC_VCE,         IF_REAL, "Initial C-E voltage"),
 IOPU("area",    BJT_AREA,           IF_REAL,    "(Emitter) Area factor"),
 IOPU("areab",   BJT_AREAB,          IF_REAL,    "Base area factor"),
 IOPU("areac",   BJT_AREAC,          IF_REAL,    "Collector area factor"), 
 IOPU("m",       BJT_M,              IF_REAL,   "Parallel Multiplier"),
 IP("ic",        BJT_IC,             IF_REALVEC, "Initial condition vector"),
 IP("sens_area", BJT_AREA_SENS,IF_FLAG, "flag to request sensitivity WRT area"),
 OPU("colnode",  BJT_QUEST_COLNODE,  IF_INTEGER, "Number of collector node"),
 OPU("basenode", BJT_QUEST_BASENODE, IF_INTEGER, "Number of base node"),
 OPU("emitnode", BJT_QUEST_EMITNODE, IF_INTEGER, "Number of emitter node"),
 OPU("substnode",BJT_QUEST_SUBSTNODE,IF_INTEGER, "Number of substrate node"),
 OPU("colprimenode",BJT_QUEST_COLPRIMENODE,IF_INTEGER,
						"Internal collector node"),
 OPU("baseprimenode",BJT_QUEST_BASEPRIMENODE,IF_INTEGER,"Internal base node"),
 OPU("emitprimenode",BJT_QUEST_EMITPRIMENODE,IF_INTEGER,
						"Internal emitter node"),
 OP("ic",    BJT_QUEST_CC,   IF_REAL, "Current at collector node"),
 OP("ib",    BJT_QUEST_CB,   IF_REAL, "Current at base node"),
 OP("ie",    BJT_QUEST_CE,   IF_REAL, "Emitter current"),
 OPU("is",   BJT_QUEST_CS,   IF_REAL, "Substrate current"),
 OP("vbe",   BJT_QUEST_VBE,  IF_REAL, "B-E voltage"),
 OP("vbc",   BJT_QUEST_VBC,  IF_REAL, "B-C voltage"),
 OP("gm",    BJT_QUEST_GM,   IF_REAL, "Small signal transconductance"),
 OP("gpi",   BJT_QUEST_GPI,  IF_REAL, "Small signal input conductance - pi"),
 OP("gmu",   BJT_QUEST_GMU,  IF_REAL, "Small signal conductance - mu"),
 OP("gx",    BJT_QUEST_GX,   IF_REAL, "Conductance from base to internal base"),
 OP("go",    BJT_QUEST_GO,   IF_REAL, "Small signal output conductance"),
 OPU("geqcb",BJT_QUEST_GEQCB,IF_REAL, "d(Ibe)/d(Vbc)"),
 OPU("gcsub",BJT_QUEST_GCSUB, IF_REAL, "Internal Subs. cap. equiv. cond."),
 OPU("gdsub", BJT_QUEST_GDSUB, IF_REAL, "Internal Subs. Diode equiv. cond."),
 OPU("geqbx",BJT_QUEST_GEQBX,IF_REAL, "Internal C-B-base cap. equiv. cond."),

 OP("cpi",BJT_QUEST_CPI, IF_REAL, "Internal base to emitter capacitance"),
 OP("cmu",BJT_QUEST_CMU, IF_REAL, "Internal base to collector capacitance"),
 OP("cbx",BJT_QUEST_CBX, IF_REAL, "Base to collector capacitance"),
 OP("csub",BJT_QUEST_CSUB, IF_REAL, "Substrate capacitance"),
 OPU("cqbe", BJT_QUEST_CQBE, IF_REAL, "Cap. due to charge storage in B-E jct."),
 OPU("cqbc", BJT_QUEST_CQBC, IF_REAL, "Cap. due to charge storage in B-C jct."),
 OPU("cqsub", BJT_QUEST_CQSUB, IF_REAL, "Cap. due to charge storage in Subs. jct."),
 OPU("cqbx", BJT_QUEST_CQBX, IF_REAL, "Cap. due to charge storage in B-X jct."),
 OPU("cexbc",BJT_QUEST_CEXBC,IF_REAL, "Total Capacitance in B-X junction"),

 OPU("qbe",  BJT_QUEST_QBE,  IF_REAL, "Charge storage B-E junction"),
 OPU("qbc",  BJT_QUEST_QBC,  IF_REAL, "Charge storage B-C junction"),
 OPU("qsub",  BJT_QUEST_QSUB,  IF_REAL, "Charge storage Subs. junction"),
 OPU("qbx",  BJT_QUEST_QBX,  IF_REAL, "Charge storage B-X junction"),
 OPU("p",    BJT_QUEST_POWER,IF_REAL, "Power dissipation"),
 OPU("sens_dc", BJT_QUEST_SENS_DC, IF_REAL,    "dc sensitivity "),
 OPU("sens_real", BJT_QUEST_SENS_REAL, IF_REAL,"real part of ac sensitivity"),
 OPU("sens_imag", BJT_QUEST_SENS_IMAG,IF_REAL,
					"dc sens. & imag part of ac sens."),
 OPU("sens_mag",  BJT_QUEST_SENS_MAG, IF_REAL,   "sensitivity of ac magnitude"),
 OPU("sens_ph",   BJT_QUEST_SENS_PH,   IF_REAL,    "sensitivity of ac phase"),
 OPU("sens_cplx", BJT_QUEST_SENS_CPLX, IF_COMPLEX, "ac sensitivity"),
 IOPU("temp",     BJT_TEMP,            IF_REAL,    "instance temperature"),
 IOPU("dtemp",    BJT_DTEMP,           IF_REAL,    "instance temperature delta from circuit")
};

IFparm BJTmPTable[] = { /* model parameters */
 OP("type",  BJT_MOD_TYPE, IF_STRING, "NPN or PNP"),
 IOPU("npn", BJT_MOD_NPN,  IF_FLAG, "NPN type device"),
 IOPU("pnp", BJT_MOD_PNP,  IF_FLAG, "PNP type device"),
 IOPU("subs", BJT_MOD_SUBS, IF_INTEGER, "Vertical or Lateral device"),
 IOP("tnom", BJT_MOD_TNOM, IF_REAL, "Parameter measurement temperature"),
 IOPR("tref", BJT_MOD_TNOM, IF_REAL, "Parameter measurement temperature"),
 IOP("is",   BJT_MOD_IS,   IF_REAL, "Saturation Current"),
 IOP("bf",   BJT_MOD_BF,   IF_REAL, "Ideal forward beta"),
 IOP("nf",   BJT_MOD_NF,   IF_REAL, "Forward emission coefficient"),
 IOP("vaf",  BJT_MOD_VAF,  IF_REAL, "Forward Early voltage"),
 IOPR("va",  BJT_MOD_VAF,  IF_REAL, "Forward Early voltage"),
 IOP("ikf",  BJT_MOD_IKF,  IF_REAL, "Forward beta roll-off corner current"),
 IOPR("ik",  BJT_MOD_IKF,  IF_REAL, "Forward beta roll-off corner current"),
 IOP("ise",  BJT_MOD_ISE,  IF_REAL, "B-E leakage saturation current"),
#ifdef BJT_COMPAT  
 IOP("c2",   BJT_MOD_C2,   IF_REAL, "Obsolete parameter name"),
#endif 
 IOP("ne",   BJT_MOD_NE,   IF_REAL, "B-E leakage emission coefficient"),
 IOP("br",   BJT_MOD_BR,   IF_REAL, "Ideal reverse beta"),
 IOP("nr",   BJT_MOD_NR,   IF_REAL, "Reverse emission coefficient"),
 IOP("var",  BJT_MOD_VAR,  IF_REAL, "Reverse Early voltage"),
 IOPR("vb",  BJT_MOD_VAR,  IF_REAL, "Reverse Early voltage"),
 IOP("ikr",  BJT_MOD_IKR,  IF_REAL, "reverse beta roll-off corner current"),
 IOP("isc",  BJT_MOD_ISC,  IF_REAL, "B-C leakage saturation current"),
#ifdef BJT_COMPAT 
 IOP("c4",   BJT_MOD_C4,   IF_REAL, "Obsolete parameter name"),
#endif 
 IOP("nc",   BJT_MOD_NC,   IF_REAL, "B-C leakage emission coefficient"),
 IOP("rb",   BJT_MOD_RB,   IF_REAL, "Zero bias base resistance"),
 IOP("irb",  BJT_MOD_IRB,  IF_REAL, "Current for base resistance=(rb+rbm)/2"),
 IOP("rbm",  BJT_MOD_RBM,  IF_REAL, "Minimum base resistance"),
 IOP("re",   BJT_MOD_RE,   IF_REAL, "Emitter resistance"),
 IOP("rc",   BJT_MOD_RC,   IF_REAL, "Collector resistance"),
 IOPA("cje", BJT_MOD_CJE,  IF_REAL,"Zero bias B-E depletion capacitance"),
 IOPA("vje", BJT_MOD_VJE,  IF_REAL, "B-E built in potential"),
 IOPR("pe",  BJT_MOD_VJE,  IF_REAL, "B-E built in potential"),
 IOPA("mje", BJT_MOD_MJE,  IF_REAL, "B-E junction grading coefficient"),
 IOPR("me",  BJT_MOD_MJE,  IF_REAL, "B-E junction grading coefficient"),
 IOPA("tf",  BJT_MOD_TF,   IF_REAL, "Ideal forward transit time"),
 IOPA("xtf", BJT_MOD_XTF,  IF_REAL, "Coefficient for bias dependence of TF"),
 IOPA("vtf", BJT_MOD_VTF,  IF_REAL, "Voltage giving VBC dependence of TF"),
 IOPA("itf", BJT_MOD_ITF,  IF_REAL, "High current dependence of TF"),
 IOPA("ptf", BJT_MOD_PTF,  IF_REAL, "Excess phase"),
 IOPA("cjc", BJT_MOD_CJC,  IF_REAL, "Zero bias B-C depletion capacitance"),
 IOPA("vjc", BJT_MOD_VJC,  IF_REAL, "B-C built in potential"),
 IOPR("pc",  BJT_MOD_VJC,  IF_REAL, "B-C built in potential"),
 IOPA("mjc", BJT_MOD_MJC,  IF_REAL, "B-C junction grading coefficient"),
 IOPR("mc",  BJT_MOD_MJC,  IF_REAL, "B-C junction grading coefficient"),
 IOPA("xcjc",BJT_MOD_XCJC, IF_REAL, "Fraction of B-C cap to internal base"),
 IOPA("tr",  BJT_MOD_TR,   IF_REAL, "Ideal reverse transit time"),
 IOPA("cjs", BJT_MOD_CJS,  IF_REAL, "Zero bias Substrate capacitance"),
 IOPR("csub", BJT_MOD_CJS,  IF_REAL, "Zero bias Substrate capacitance"),
 IOPA("vjs", BJT_MOD_VJS,  IF_REAL, "Substrate junction built in potential"),
 IOPR("ps",  BJT_MOD_VJS,  IF_REAL, "Substrate junction built in potential"),
 IOPA("mjs", BJT_MOD_MJS,  IF_REAL, "Substrate junction grading coefficient"),
 IOPR("ms",  BJT_MOD_MJS,  IF_REAL, "Substrate junction grading coefficient"),
 IOP("xtb",  BJT_MOD_XTB,  IF_REAL, "Forward and reverse beta temp. exp."),
 IOP("eg",   BJT_MOD_EG,   IF_REAL, "Energy gap for IS temp. dependency"),
 IOP("xti",  BJT_MOD_XTI,  IF_REAL, "Temp. exponent for IS"),
 IOP("fc",   BJT_MOD_FC,   IF_REAL, "Forward bias junction fit parameter"),
 IOP("kf", BJT_MOD_KF, IF_REAL, "Flicker Noise Coefficient"),
 IOP("af", BJT_MOD_AF, IF_REAL,"Flicker Noise Exponent"),
 OPU("invearlyvoltf",BJT_MOD_INVEARLYF,IF_REAL,"Inverse early voltage:forward"),
 OPU("invearlyvoltr",BJT_MOD_INVEARLYR,IF_REAL,"Inverse early voltage:reverse"),
 OPU("invrollofff", BJT_MOD_INVROLLOFFF, IF_REAL,"Inverse roll off - forward"),
 OPU("invrolloffr", BJT_MOD_INVROLLOFFR, IF_REAL,"Inverse roll off - reverse"),
 OPU("collectorconduct",BJT_MOD_COLCONDUCT,IF_REAL,"Collector conductance"),
 OPU("emitterconduct", BJT_MOD_EMITTERCONDUCT,IF_REAL, "Emitter conductance"),
 OPU("transtimevbcfact",BJT_MOD_TRANSVBCFACT,IF_REAL,"Transit time VBC factor"),
 OPU("excessphasefactor",BJT_MOD_EXCESSPHASEFACTOR,IF_REAL, "Excess phase fact."),
 IOP("iss", BJT_MOD_ISS, IF_REAL, "Substrate Jct. Saturation Current"),
 IOP("ns", BJT_MOD_NS, IF_REAL, "Substrate current emission coefficient"),
 IOP("tlev", BJT_MOD_TLEV, IF_INTEGER, "Temperature equation selector"),
 IOP("tlevc", BJT_MOD_TLEVC, IF_INTEGER, "Temperature equation selector"),
 IOP("tbf1", BJT_MOD_TBF1, IF_REAL, "BF 1. temperature coefficient"),
 IOP("tbf2", BJT_MOD_TBF2, IF_REAL, "BF 2. temperature coefficient"),
 IOP("tbr1", BJT_MOD_TBR1, IF_REAL, "BR 1. temperature coefficient"),
 IOP("tbr2", BJT_MOD_TBR2, IF_REAL, "BR 2. temperature coefficient"),
 IOP("tikf1", BJT_MOD_TIKF1, IF_REAL, "IKF 1. temperature coefficient"),
 IOP("tikf2", BJT_MOD_TIKF2, IF_REAL, "IKF 2. temperature coefficient"),
 IOP("tikr1", BJT_MOD_TIKR1, IF_REAL, "IKR 1. temperature coefficient"),
 IOP("tikr2", BJT_MOD_TIKR2, IF_REAL, "IKR 2. temperature coefficient"),
 IOP("tirb1", BJT_MOD_TIRB1, IF_REAL, "IRB 1. temperature coefficient"),
 IOP("tirb2", BJT_MOD_TIRB2, IF_REAL, "IRB 2. temperature coefficient"),
 IOP("tnc1", BJT_MOD_TNC1, IF_REAL, "NC 1. temperature coefficient"),
 IOP("tnc2", BJT_MOD_TNC2, IF_REAL, "NC 2. temperature coefficient"),
 IOP("tne1", BJT_MOD_TNE1, IF_REAL, "NE 1. temperature coefficient"),
 IOP("tne2", BJT_MOD_TNE2, IF_REAL, "NE 2. temperature coefficient"),
 IOP("tnf1", BJT_MOD_TNF1, IF_REAL, "NF 1. temperature coefficient"),
 IOP("tnf2", BJT_MOD_TNF2, IF_REAL, "NF 2. temperature coefficient"),
 IOP("tnr1", BJT_MOD_TNR1, IF_REAL, "NR 1. temperature coefficient"),
 IOP("tnr2", BJT_MOD_TNR2, IF_REAL, "NR 2. temperature coefficient"),
 IOP("trb1", BJT_MOD_TRB1, IF_REAL, "RB 1. temperature coefficient"),
 IOP("trb2", BJT_MOD_TRB2, IF_REAL, "RB 2. temperature coefficient"),
 IOP("trc1", BJT_MOD_TRC1, IF_REAL, "RC 1. temperature coefficient"),
 IOP("trc2", BJT_MOD_TRC2, IF_REAL, "RC 2. temperature coefficient"),
 IOP("tre1", BJT_MOD_TRE1, IF_REAL, "RE 1. temperature coefficient"),
 IOP("tre2", BJT_MOD_TRE2, IF_REAL, "RE 2. temperature coefficient"),
 IOP("trm1", BJT_MOD_TRM1, IF_REAL, "RBM 1. temperature coefficient"),
 IOP("trm2", BJT_MOD_TRM2, IF_REAL, "RBM 2. temperature coefficient"),
 IOP("tvaf1", BJT_MOD_TVAF1, IF_REAL, "VAF 1. temperature coefficient"),
 IOP("tvaf2", BJT_MOD_TVAF2, IF_REAL, "VAF 2. temperature coefficient"),
 IOP("tvar1", BJT_MOD_TVAR1, IF_REAL, "VAR 1. temperature coefficient"),
 IOP("tvar2", BJT_MOD_TVAR2, IF_REAL, "VAR 2. temperature coefficient"),
 IOP("ctc", BJT_MOD_CTC, IF_REAL, "CJC temperature coefficient"),
 IOP("cte", BJT_MOD_CTE, IF_REAL, "CJE temperature coefficient"),
 IOP("cts", BJT_MOD_CTS, IF_REAL, "CJS temperature coefficient"),
 IOP("tvjc", BJT_MOD_TVJC, IF_REAL, "VJC temperature coefficient"),
 IOP("tvje", BJT_MOD_TVJE, IF_REAL, "VJE temperature coefficient"),
 IOP("tvjs", BJT_MOD_TVJS, IF_REAL, "VJS temperature coefficient"),
 IOP("titf1",BJT_MOD_TITF1, IF_REAL, "ITF 1. temperature coefficient"), 
 IOP("titf2",BJT_MOD_TITF2, IF_REAL, "ITF 2. temperature coefficient"), 
 IOP("ttf1", BJT_MOD_TTF1, IF_REAL, "TF 1. temperature coefficient"), 
 IOP("ttf2", BJT_MOD_TTF2, IF_REAL, "TF 2. temperature coefficient"), 
 IOP("ttr1", BJT_MOD_TTR1, IF_REAL, "TR 1. temperature coefficient"), 
 IOP("ttr2", BJT_MOD_TTR2, IF_REAL, "TR 2. temperature coefficient"), 
 IOP("tmje1",BJT_MOD_TMJE1, IF_REAL, "MJE 1. temperature coefficient"),
 IOP("tmje2",BJT_MOD_TMJE2, IF_REAL, "MJE 2. temperature coefficient"),
 IOP("tmjc1",BJT_MOD_TMJC1, IF_REAL, "MJC 1. temperature coefficient"),
 IOP("tmjc2",BJT_MOD_TMJC2, IF_REAL, "MJC 2. temperature coefficient"),
 IOP("tmjs1",BJT_MOD_TMJS1, IF_REAL, "MJS 1. temperature coefficient"),
 IOP("tmjs2",BJT_MOD_TMJS2, IF_REAL, "MJS 2. temperature coefficient"),
 IOP("tns1", BJT_MOD_TNS1, IF_REAL, "NS 1. temperature coefficient"),
 IOP("tns2", BJT_MOD_TNS2, IF_REAL, "NS 2. temperature coefficient"),
 IOP("nkf", BJT_MOD_NKF, IF_REAL, "NKF High current beta rolloff exponent")
};

char *BJTnames[] = {
    "collector",
    "base",
    "emitter",
    "substrate"
};


int	BJTnSize = NUMELEMS(BJTnames);
int	BJTpTSize = NUMELEMS(BJTpTable);
int	BJTmPTSize = NUMELEMS(BJTmPTable);
int	BJTiSize = sizeof(BJTinstance);
int	BJTmSize = sizeof(BJTmodel);
