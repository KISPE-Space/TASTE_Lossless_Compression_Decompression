INCLUDEPATH += work/dataview/C
HEADERS += work/dataview/C/dataview-uniq.h
HEADERS += work/dataview/Ada/src/*.ads
include(datacompressor/datacompressor.pro)
include(datauncompressor/datauncompressor.pro)
include(testcompressuncompress/testcompressuncompress.pro)
include(uartotherend/uartotherend.pro)

