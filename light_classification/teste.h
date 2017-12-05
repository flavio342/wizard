const int SIGNAL_SIZE = 50;
const int INPUT_SIZE = SIGNAL_SIZE*6;
const int BITS_PER_RAM = 35;
const int N_NEURONIOS = INPUT_SIZE/BITS_PER_RAM;
const int INPUT_FACTOR = 5;

const PROGMEM String labels[5] = {"front","idle","right","back","left"};
const PROGMEM int nNeuronios[] = {8};
const PROGMEM int nIndicesDeEntradas[] = {35};
const PROGMEM int indicesDeEntradas[5][8][35] = {{{175,205,12,210,30,263,247,89,151,19,139,34,29,219,124,134,7,20,224,59,108,218,221,297,8,93,299,280,49,85,10,168,235,262,220},{129,177,143,288,242,67,254,193,258,160,147,21,132,273,110,256,202,31,100,68,51,189,217,188,277,253,72,209,44,222,5,90,185,82,138},{61,270,260,36,144,180,23,201,236,252,43,246,294,56,148,73,276,99,145,184,106,191,211,170,155,156,200,104,207,243,240,259,126,33,77},{226,107,232,228,141,264,164,274,183,159,4,66,87,70,69,271,231,92,94,11,54,292,9,190,95,223,213,290,150,238,65,295,2,111,40},{53,130,216,261,199,157,142,32,293,37,48,105,291,113,195,58,269,0,122,22,16,13,64,167,84,117,186,241,266,17,123,234,245,152,119},{63,250,214,257,284,275,197,79,255,114,91,1,227,248,41,251,127,281,3,237,176,173,244,196,62,121,118,268,212,78,81,131,149,133,24},{42,96,6,249,76,289,174,26,178,120,80,265,50,182,103,278,136,98,45,198,14,162,206,102,161,163,179,115,208,86,35,165,18,158,285},{287,137,60,128,57,112,286,239,101,83,153,203,15,25,135,192,75,38,171,187,267,181,154,27,298,116,52,88,194,46,97,283,225,204,172}},{{190,216,219,115,141,217,41,8,284,70,180,85,275,29,9,23,147,118,46,86,158,196,33,240,204,81,232,186,119,90,236,221,171,144,218},{140,120,255,184,98,55,246,214,2,79,297,210,133,38,10,116,208,279,114,163,261,66,107,282,290,50,77,58,139,5,242,183,130,276,106},{1,138,269,137,60,27,197,155,96,54,75,249,112,202,209,18,288,149,220,182,281,42,172,192,7,95,135,20,153,298,24,227,52,280,108},{53,88,134,132,173,136,17,212,238,194,80,254,161,51,101,273,126,259,43,62,292,36,32,22,257,223,28,283,200,117,265,185,94,245,65},{277,30,201,124,295,263,234,177,166,226,39,72,230,91,187,247,267,89,162,274,207,296,57,278,222,12,157,113,40,178,299,127,102,154,244},{199,37,6,239,286,59,103,99,159,248,105,151,67,69,176,48,21,243,260,215,152,97,34,198,272,93,262,251,203,122,131,165,109,78,168},{235,268,49,170,211,189,225,71,84,233,104,156,179,110,121,35,258,4,228,44,83,237,128,175,160,64,14,195,63,16,193,271,47,45,92},{100,148,231,56,270,291,256,164,11,19,224,82,285,250,111,15,145,61,287,289,191,213,188,293,125,174,206,31,26,73,123,169,205,294,129}},{{268,15,95,158,71,86,24,30,272,47,136,98,3,99,21,169,137,60,41,180,1,232,208,31,120,189,126,239,231,129,50,217,172,262,117},{223,40,100,292,89,295,256,271,65,82,296,43,216,196,154,219,222,218,267,53,28,227,115,37,75,210,46,67,185,140,12,146,290,269,101},{202,97,186,285,281,199,198,197,13,191,103,134,74,84,142,6,106,161,135,184,124,164,220,274,64,85,167,214,153,250,90,91,81,96,252},{159,151,109,215,131,4,209,288,112,224,38,221,110,248,204,44,48,244,193,298,264,155,254,80,190,253,283,297,116,88,247,33,234,270,149},{235,32,147,277,29,133,45,39,228,150,93,201,66,61,206,77,287,263,72,182,22,179,8,141,105,138,104,108,212,5,68,42,69,0,35},{20,58,213,36,162,165,7,34,280,163,52,236,130,51,174,94,291,78,143,207,173,245,183,181,251,257,178,148,16,170,194,177,203,260,258},{59,259,226,273,26,289,242,9,205,157,92,127,10,233,230,122,225,255,111,156,200,246,166,27,107,132,211,144,160,125,294,14,240,171,123},{265,145,79,119,2,168,57,243,128,121,229,114,54,176,275,279,56,293,11,187,23,286,238,284,62,266,113,55,76,83,63,195,118,276,17}},{{152,99,64,65,12,77,36,88,61,84,138,114,26,262,147,34,33,58,85,285,182,238,288,57,287,27,0,230,173,160,239,25,187,63,213},{13,80,144,141,158,3,295,271,52,180,164,4,45,214,2,286,195,82,222,8,165,162,24,105,47,233,161,185,21,172,254,255,215,242,290},{35,224,124,261,294,23,269,96,212,111,86,193,110,157,297,49,56,189,210,197,203,109,42,234,245,186,125,273,146,70,275,248,247,44,127},{216,192,55,272,17,259,226,73,179,175,95,177,97,249,221,102,117,260,225,250,257,7,289,268,15,220,150,202,37,194,278,71,100,280,218},{137,241,89,118,116,168,79,115,267,188,208,134,91,232,68,132,135,81,258,217,40,43,133,198,46,159,72,103,6,104,293,154,75,240,20},{235,39,78,87,169,264,178,196,41,30,142,83,69,98,38,283,277,5,59,16,120,106,174,51,166,101,74,143,129,207,228,53,276,11,236},{90,29,176,209,205,251,119,211,229,66,231,227,183,284,93,126,256,153,200,219,94,223,9,299,48,76,206,266,170,204,108,163,145,128,92},{31,67,270,14,279,244,263,19,113,298,155,112,281,123,291,184,140,50,10,28,167,274,265,252,237,201,131,107,190,136,151,148,191,60,292}},{{223,214,286,217,232,189,89,297,111,218,279,200,99,271,97,33,159,293,245,226,106,130,266,102,181,48,224,95,69,143,255,81,147,270,5},{14,71,277,237,55,62,258,91,282,175,45,10,287,88,133,136,112,108,273,269,145,272,2,157,118,83,278,105,137,53,76,174,180,123,253},{243,179,191,27,178,247,260,75,139,57,160,155,183,275,170,149,113,177,103,211,43,40,12,250,34,229,210,262,153,169,142,230,166,80,240},{65,268,182,61,291,156,288,0,284,70,29,77,209,38,292,206,86,141,188,295,161,39,222,20,116,47,203,289,41,85,162,216,68,11,98},{87,236,64,127,256,259,257,52,79,59,4,164,221,263,42,195,16,227,21,50,235,204,124,35,196,192,283,54,281,90,165,150,9,138,238},{129,140,13,125,228,8,233,198,132,28,167,15,249,31,254,185,25,267,265,119,190,18,82,154,32,208,212,78,6,274,104,296,131,187,193},{220,168,46,30,215,17,44,158,219,248,207,290,73,264,173,1,146,114,26,19,22,251,184,152,298,244,49,242,172,186,56,120,202,194,117},{126,163,122,51,92,58,197,261,100,135,246,37,109,276,234,115,67,60,7,285,74,63,23,299,107,201,134,241,252,36,199,110,24,280,94}}};
const PROGMEM int nDados[5][8] = {{32,34,32,36,19,28,43,35},{1,1,1,1,1,1,1,1},{25,31,25,34,39,29,35,41},{36,42,29,26,48,38,41,25},{21,17,22,34,30,22,27,22}};
const PROGMEM long long int tabelaDeDadosKeys[5][8][48] = {{{14560447730,16707929330,5970511058,14694666226,5433607250,5970510930,14560447954,14560447698,16842147058,5970513106,14694665714,16842147570,5970478162,14694663410,14694663282,14560445650,5433640018,5953733714,5970513362,4884186130,14560445554,5970510866,14560445682,5433607248,14694663794,14560447986,5953209426,14694663922,14560445522,16842149874,14543668306,16842149618,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{22380791643,24528275281,22380790611,17529782865,18066948688,24528275283,21841658385,24528275291,21843624529,21843887697,18066948944,22380791763,21841789521,24528275409,21843886673,24528275411,22380790619,21843625553,24528275419,22380791761,18066948945,22380790609,17530044945,22380791771,22378693459,22378660433,24528275025,22380790747,22380791633,22380791635,21841527377,18066948947,18066948946,22378693467,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{33742733710,33747321295,24077943182,24077943183,7970308494,33747190222,33747325391,33746665870,33742733775,33747190158,33742864847,33742995919,33743000015,33747190159,33743126991,33742209422,33742995854,6897549710,33742733711,33742864783,32650576270,33742995855,33747194319,7972405646,33747190223,22988013964,33743126927,25151750543,24077418894,33742471566,33743131087,16560243086,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{10363654295,9144160263,10361565343,10233304087,10367979671,10368054423,10217902087,10367979543,10352119831,10368054687,10368054431,10367856791,8618299415,9680506887,10233106455,10367856799,10363662495,10233630743,10368046231,10361557143,10367848599,10368046103,10217377798,10217377799,10360516759,10363654167,10229436439,10233828375,9155170327,10363662487,10368054679,10226290711,10352119815,10368045079,10367848471,10228912151,0,0,0,0,0,0,0,0,0,0,0,0},{28381274737,28381536881,28381542001,28453107313,28381799025,28381012529,28196987505,28385998449,28113105457,28381804145,28381540913,28381803121,26234053169,28381012593,28113101361,28453106289,28385997425,28113105521,28096590449,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{28716238783,10848371467,29789980607,28565112751,10848371471,10848371599,10848372623,28028241839,28699330495,29773203375,34084947967,28565243791,29638985615,28699461551,28716107711,29773203391,28028241803,28162459579,28699461567,28162459583,28162459451,29638985647,28179236799,28565112719,10847324047,29789980671,28028241807,28028241675,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{21648197780,23284504821,21656586388,22721939604,22747109524,31874570485,22747105460,22730332308,23267723413,31337568500,31337568501,31337568436,22747633909,22747633908,22747105428,22747109556,31337175284,22747633813,22730328212,22193985685,21657110676,22730852500,23284504725,22747633844,22747633845,22747629716,22747633812,31337699573,31337699572,22747633877,22193985749,4476651668,31337171124,22193981589,31337175220,23284500629,4476651652,23284504757,31337699508,31337699509,21657110677,21647935636,23284504789,0,0,0,0,0},{16759802794,16725986082,16759802656,16725986090,16759802658,11348888352,34174552874,34208108458,16759802666,34208107434,34208107450,16726231842,16717597472,16717597480,16726248226,34174553898,16759802810,16726248234,16725986050,34174291754,34165902120,34208108474,16725986080,34208107306,11348871968,8136297250,16759802802,17028238266,34174290730,8134986530,8136035106,34208108330,16759802786,12422613792,16725852930,0,0,0,0,0,0,0,0,0,0,0,0,0}},{{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},{{32161036506,31757334011,32194657499,32178142715,31690225147,31774373371,32026818011,31775421947,5920419928,32026818043,5920420056,32161037819,32026816730,5920420058,23167399419,32194656474,32043857403,32178077179,31690223834,32178075131,23100289242,23167398106,23167399131,32211697147,31757332698,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{25758250647,34356592311,31647071891,23057135251,31655460755,22922831505,31655460759,22922897041,22922897043,23057118867,34356592319,18627929730,18627864192,25758246551,22922897025,22922897027,23057114770,23057114771,25758250679,23057114754,34356592575,22922831488,22922831489,25758269119,23057114755,25758267071,31655456659,18762147458,25758250687,25204598407,23057133203,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{26934533823,25843736255,26867408575,29091520191,25793666751,25793402559,25776101055,25860789951,25860773567,26934517439,25776625343,29014892223,25860775615,25776627391,29090471615,25860511423,25793140415,29082017471,26934255295,25843734207,29090406079,25860791999,29082001087,25869246143,25793664703,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{7498521398,8572296183,2998032948,7516085118,2998032950,8589597695,8589597694,2995788324,8589073407,8572296191,7498554294,8438045302,7364303734,7364303478,7293000244,8589826942,7381867070,7381867390,7297194548,2998016564,7381867134,7381080638,7293000246,7364303670,8589859838,8589859839,7292983860,7498521462,7431445430,8572296182,7364303412,8438045566,7364303414,7297194550,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{19427692662,19427692918,17280204918,17280209270,17280209014,17280079222,19427972598,30031173631,19427956214,17280226806,17280210422,17280073846,17817097718,25333555190,19964581366,29494302207,19427694070,29494040063,19427710454,17280210294,17280077942,17280078198,17280075254,33923489782,17280206326,19427693942,17280075126,19964827126,24259796982,19964829686,29091386871,24259813366,17280073814,29762740223,29225604599,34326142975,33923489783,17280206198,27346556415,0,0,0,0,0,0,0,0,0},{32642868807,30361167431,32710239815,13248407047,32714499783,32709977671,30432798407,13181289989,30432732743,13248669191,13252863559,13181298183,30567016135,13248407111,13252929095,13181298181,13248669255,13181298247,13252929223,32714171975,30428538439,30365361735,30428276295,13181289991,32714434119,12912862724,13185492551,12912862727,30566688327,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{30568047917,33252403005,32715531565,32706553092,33243489564,32568140036,30290624768,30290624772,30559134980,30420722948,30420656388,34317233420,30559068428,32706552076,33252403133,34317231372,34326146877,30559068420,33789275949,34326146861,30559069444,34326147005,30554875140,30420657412,30554874116,33789273901,32706618628,33780362508,32706552068,33243489556,32706618636,21830721796,32715532077,33780886829,32702424324,0,0,0,0,0,0,0,0,0,0,0,0,0},{22974250994,22982514675,22972471024,25230137335,22974043890,22974267379,25230671863,25163554807,22981974002,33820737527,22974109426,25129981942,25230655478,25230802935,22973519602,5792666864,22973519600,5792601328,25230137333,5658449136,22981990387,25230661623,22973585136,25229072373,22972470512,5658383600,22974250739,25230786551,25230786550,25161979893,22973601523,33820721143,22982524915,22980859888,22982508530,22972536561,22972536560,22974109427,25163562999,22973585138,22974250738,0,0,0,0,0,0,0}},{{7108467971,7242751363,7073864963,7073864962,7057087875,6520225171,17179852699,77765888,7090650515,77765891,77765890,7107493267,7057096083,7108533507,15832694163,7242759571,7073865091,7057087747,7241710995,4372733187,6520216835,6520216834,4372733186,7074913539,6538042626,16910630811,7073873299,16906435987,6536994051,7108541843,7224933779,15831645587,7090716035,6520216963,6538042627,10657024,0,0,0,0,0,0,0,0,0,0,0,0},{16042887711,16051309087,204016159,15504771101,9062516765,6914902045,15504836637,7461144601,2620983839,6915885081,472451101,8794081821,9062386207,11210000925,6913787929,15504967709,33235377759,2619934749,7452755993,33231178271,11209869855,9062385693,2619869209,9063434783,16051276319,472451615,15504968223,9062517277,7459047449,472451613,472385561,16042887197,2619869213,6914836509,9062517279,15504902169,472385565,9062386205,470288409,33231182431,11210000927,15506016285,0,0,0,0,0,0},{7890887089,16480824821,16480821681,16480823472,11111066780,15406033072,16479772848,16480824753,7823712656,16497598961,16480823729,7890887153,16631819773,16496553405,16497601981,34349088255,3528810640,7890887121,16631819709,16480821745,7890887056,7890887057,16496552368,7823778193,17168690685,7823712689,16631818673,16497602045,16480824765,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{24429714079,24429714071,24563931807,25660751583,24161213087,24160163999,24160163998,24294381727,24160164503,24566028959,6980294806,24584903327,24295496351,24160164511,24431811223,25660751519,24294382239,24295430815,24161213079,24582806175,6980294814,7114512542,24587000479,24587008671,24160163990,24160163991,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{29490123190,20629524916,3439952048,3449655472,20629524912,3711140276,29221556662,3441000880,3441004976,3439427760,3708912052,3443102132,3439394992,3449655732,12033036726,12032508066,20898091444,3448344752,20898058676,33785090486,20629492144,3711140260,3439923376,3440476592,3449622704,29489992118,20629491888,20900057524,20629524656,3440443568,3709043124,33789310455,20628476080,12032508082,20629492148,20897960372,20897927604,3449393328,12041687478,12032508338,3439956144,33789284790,3451752884,25193058740,20628443312,12301468086,33789284855,33789284854},{4836911980,17721813885,537750124,22041947133,537750060,24191691775,4862077948,17721813629,541944428,24191527805,558721900,541944684,558722028,558853100,541944444,24189430653,24191659005,558721644,4836911916,24191527933,4862077932,4836911932,24189430781,22033558397,22016781181,541944620,554527468,24225246207,4853689324,541944364,17721797181,22025169725,4836911996,7009561596,32883338239,24172653437,558721772,17721813565,0,0,0,0,0,0,0,0,0,0},{4197296562,4197255600,4197288370,4272794034,4289571250,4197288374,4197288882,4205685170,4205683632,4163174832,4289046960,4197256118,21470510007,4163176880,4163701168,21469440950,4289045424,21470505907,4205685686,4163701170,30060445623,4272794550,4289569714,4289569712,4063037874,4029483442,21469438898,30060444599,4272794546,4289044912,4197256114,21470505911,4197288886,4196770736,4289571766,4197297078,4197255606,4289571762,1881475504,4205685682,4197255602,0,0,0,0,0,0,0},{17028300715,14846934947,14844837506,5753682563,5720128131,14343879587,14310063747,14880751523,5753945003,14880489379,14880751531,14343618467,14343617411,34342420395,14343879595,14880489347,14343880611,14343618179,5753944995,14310062723,14343617443,14343617155,14880489091,14343618435,5753682819,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},{{33548859767,15568894719,13114178167,33822538751,4524243511,15563651711,32475085431,32743554047,15295216247,32475085439,4524242999,32743521279,33822604287,32743520895,4523718711,15294691447,4523718707,32748796927,13114178103,33548925303,4524243575,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{22915577315,32178698227,4636800451,4645189059,4636800483,32042383347,21825058275,23452448227,23435671011,32044480499,5710525923,34173089267,22898800099,32042382819,21825058243,4645189091,34326181875,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{2519537808,2519538832,2653814682,2653814683,372054160,20370554779,2519539088,2519563664,2519538064,2653814162,2519563408,338495632,2519570832,2519596432,337971344,2519580048,19833683867,2519547024,338499728,19833659289,2653814674,372054416,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{29485608322,29485608902,29527818223,29483502978,29485608898,10134654338,29519163334,29519167438,29517061518,10134652288,29485608390,29525450126,10135178626,12301545410,29519163342,29483502990,10139372930,29479308674,29527814127,12301544834,12303633794,29481414594,10135176576,12299439490,29485608386,29462531458,29527814126,12301544898,10151955842,10134652290,10135176578,12286856578,12282662274,29527818222,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{4179931462,4179661250,4179931590,17102795207,4045451590,34350823911,4213551558,4179669446,25760872934,4214602182,4179669318,4045779270,4179669442,8508520902,25760741862,8513763782,4179669314,4045713734,8509569478,34350823910,4213553606,8508518854,4179996998,4213486022,4045451586,25756547558,17102797255,25760741830,4179997126,25760889318,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{34204002172,33935570940,32825909372,32861823612,32859726460,34204006396,32859725948,32826171516,32861823868,34204002300,32826172028,34208200700,32825909884,32861829116,28522545276,27985674364,27985674300,32861824636,32861824124,32825901180,32817512572,32861824892,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{7276061725,11412493,3853509661,25600976285,548332557,21037573277,565175325,8353998109,25634531229,548283405,565060621,548283421,21037573789,25600976797,548316189,7276061981,548316173,2712658973,28189709,8349803805,25600976157,11150365,565093405,548332573,8421106973,565109789,2981094429,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{23864123214,24400990026,24409784174,24400994126,24409800558,24401395534,24409522030,24401125198,24410849262,23864119114,25484591087,25501368303,25484590959,25483542382,24409513838,25483542383,21716635466,24401133390,23864053578,24419237838,23864123210,24401121098,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}}};
const PROGMEM int tabelaDeDadosValues[5][8][48]= {{{1,3,10,1,1,10,5,1,3,1,2,28,2,4,1,17,1,2,1,1,6,1,1,1,16,1,1,35,13,3,1,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{21,7,4,1,2,5,1,4,1,1,1,2,3,1,1,3,4,2,43,1,1,9,1,15,4,1,8,2,14,6,2,1,1,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{3,6,2,2,1,1,8,5,3,1,5,14,4,3,43,3,11,1,10,1,1,12,1,3,6,1,2,1,2,9,13,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{2,1,1,1,1,7,2,1,1,6,6,1,3,3,1,4,11,4,16,1,2,42,1,2,1,33,4,6,1,1,1,1,3,3,3,2,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,1,23,2,1,1,15,4,73,1,38,1,1,1,12,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{17,1,45,2,3,3,1,2,2,2,6,4,18,1,11,19,1,1,2,6,2,1,9,8,1,3,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{4,9,10,1,2,37,1,2,1,1,3,1,3,1,4,6,7,1,7,1,6,5,2,3,1,1,3,7,19,1,1,1,1,10,2,2,1,1,4,1,3,1,1,0,0,0,0,0},{3,2,1,3,5,1,2,2,3,7,38,2,4,2,16,5,7,3,1,3,1,7,1,4,2,1,27,2,9,1,1,2,8,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0}},{{116,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{116,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{116,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{116,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{116,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{116,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{116,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{116,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},{{2,1,2,2,1,6,1,4,1,1,12,1,3,17,1,2,5,6,3,1,12,27,1,27,10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,1,1,3,1,1,2,3,8,1,2,2,3,4,1,1,20,3,1,26,6,19,1,14,8,1,3,9,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{2,1,1,49,9,11,2,1,1,3,17,2,13,1,1,1,2,1,1,4,1,1,6,2,16,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{3,12,16,1,19,1,1,2,1,4,1,3,1,2,1,1,1,1,1,15,1,2,1,2,1,25,1,1,1,5,1,1,8,12,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,1,1,16,3,2,1,6,1,23,2,1,3,1,1,7,2,1,7,7,1,1,1,3,1,2,1,4,3,2,6,1,1,1,27,4,1,1,0,0,0,0,0,0,0,0,0},{2,2,1,7,30,3,12,1,1,2,1,58,1,2,2,2,1,5,2,1,1,2,1,1,1,1,1,4,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,2,2,6,2,2,1,1,1,1,14,1,4,2,11,1,1,12,1,1,5,36,1,6,4,1,5,4,2,2,11,1,1,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,3,15,1,2,1,1,1,1,41,2,1,1,1,1,1,1,21,1,1,1,1,5,1,1,1,1,1,1,1,1,6,1,1,2,3,16,2,1,3,1,0,0,0,0,0,0,0}},{{2,1,3,1,2,7,12,1,1,1,1,1,2,1,6,1,1,3,5,2,36,1,1,6,1,1,5,1,22,2,1,1,1,1,26,1,0,0,0,0,0,0,0,0,0,0,0,0},{2,1,1,1,1,2,1,1,1,2,11,1,2,1,1,4,12,2,1,1,1,1,2,1,5,6,4,1,2,1,2,2,8,24,1,1,36,1,8,1,3,1,0,0,0,0,0,0},{16,1,12,1,1,1,1,1,1,2,3,22,7,1,3,12,2,9,1,5,1,41,1,1,1,1,1,3,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{5,1,17,12,1,5,2,2,4,14,18,1,3,4,1,2,2,10,3,2,3,6,5,2,10,26,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{4,4,3,11,6,1,2,2,1,3,1,1,9,1,1,1,7,2,1,1,3,1,1,2,1,1,7,1,29,2,1,12,1,1,2,3,1,1,1,3,1,11,1,1,5,2,1,3},{2,4,29,2,7,1,2,2,19,1,1,1,3,1,2,1,4,1,1,3,4,1,4,1,5,1,5,1,4,1,1,2,3,2,12,2,24,1,0,0,0,0,0,0,0,0,0,0},{6,2,30,1,4,7,1,1,1,1,1,1,1,1,1,3,1,4,2,5,12,2,2,1,1,1,1,1,1,1,1,6,2,1,3,4,23,9,1,1,13,0,0,0,0,0,0,0},{1,1,1,8,1,19,2,12,1,1,7,1,9,13,35,3,1,2,2,1,26,8,1,1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},{{1,1,2,15,6,1,1,1,1,1,18,1,14,1,82,1,1,8,2,1,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,18,9,15,2,1,9,11,17,1,1,2,30,5,12,5,23,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{10,8,14,4,9,10,1,1,2,7,7,21,2,9,1,1,5,4,40,2,3,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,3,37,2,2,5,4,1,1,16,1,1,10,3,1,1,2,1,1,5,2,2,2,5,2,1,1,1,4,28,8,1,3,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{8,1,9,1,19,22,18,3,13,3,7,2,1,2,3,1,3,3,15,1,5,6,3,1,2,1,1,2,5,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,10,17,1,4,22,2,3,1,1,1,5,2,6,24,2,1,21,7,15,7,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{2,37,1,1,6,1,7,1,8,7,3,1,1,6,3,8,4,22,2,3,29,1,1,1,1,4,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{3,1,11,2,4,1,6,16,1,52,5,12,9,1,7,14,7,5,1,1,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}}};

int definirBleachingDeUmaRede(int rede) {

  int somaHits = 0;
  int nHits = 0;
  for (int neuronio = 0; neuronio < pgm_read_word_near(nNeuronios); neuronio++) {
    for (int hit = 0; hit < pgm_read_word_near(&nDados[rede][neuronio]); hit++) {
      somaHits += pgm_read_word_near(&tabelaDeDadosValues[rede][neuronio][hit]);
      if (pgm_read_word_near(&tabelaDeDadosValues[rede][neuronio][hit]) > 0) {
        nHits++;
      }
    }
  }
  return somaHits / nHits;
}

int* definirBleachingDasRedes() {

  int* somaBleaching;

  somaBleaching = (int*) malloc (5 * sizeof(int));

  for (int i = 0; i < 5; i++) {
    somaBleaching[i] = definirBleachingDeUmaRede(i);
  }
  return somaBleaching;
}

long powered(int base, int expo){
  long result = 1;
  for(int i=0;i<expo;i++){
    result *= base;
  }
  return result;
}

long binConv(String binary)
{
  long decimal = 0;
  
  for (int counter = 0; counter < BITS_PER_RAM ; counter++)
  {
    if (binary[counter] == '1'){
      decimal += powered(2,BITS_PER_RAM - 1 - counter); 
    }
  }
  return decimal;
}

int testeDeEntrada(int rede, int* entrada, int limiteDoBleaching) {

  int resultado = 0;
  for (int neuronio = 0; neuronio < pgm_read_word_near(nNeuronios); neuronio++) {
    
    String tabelaKey = "";
    for (int indice = 0; indice < pgm_read_word_near(nIndicesDeEntradas); indice++) {
      if (entrada[pgm_read_word_near(&indicesDeEntradas[rede][neuronio][indice])] > 0) {
        tabelaKey += "1";
      } else {
        tabelaKey += "0";
      }
    }
    
    for (int dado = 0; dado < pgm_read_word_near(&nDados[rede][neuronio]); dado++) {
      if (binConv(tabelaKey) == pgm_read_dword(&tabelaDeDadosKeys[rede][neuronio][dado])) {
        if (pgm_read_word_near(&tabelaDeDadosValues[rede][neuronio][dado]) > 0) {
          resultado++;
        }
      }
    }

  }
  return resultado;
}

String testarRedes(int* limiteDoBleaching, int* entrada) {

  int melhorResultado = -1;
  String labelDoMelhorResultado = "";

  for (int rede = 0; rede < 5; rede++) {
    int resultado = testeDeEntrada(rede, entrada, limiteDoBleaching[rede]);
    if (resultado > melhorResultado) {
      melhorResultado = resultado;
      labelDoMelhorResultado = labels[rede];
    }
  }
  if(melhorResultado == 0){
    labelDoMelhorResultado = "idle";
    Serial.println("no hit");
  }
  return labelDoMelhorResultado;
}



