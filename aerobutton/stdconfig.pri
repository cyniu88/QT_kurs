######################################################################
# HowTo USE
######################################################################
# In pro-file:
# TMPDIR - set Temporary Directory (optionale)
# DESTDIR - set Destination Directory (optionale)
# TRDIR - set Translations Directory (optionale) 
#
# DEBUGCONFIG = false  - off pro-file debuging  (optionale)
#
# HARDCODED += <name> - hardcoded (defined) <name> in DEFINE  (optionale)
#	here is <name> suported:
#		target			- #define TARGET = $${TARGET}
#		translationdir	- #define TRDIR = $${TRDIR}
#
# include($$(LIBS)/MyPri/stdconfig.pri)
#
#
######################################################################



#=========== Temporary directory ========
isEmpty(TEMPDIR){
	isEmpty(TMPDIR){
		TMPDIR = ./tmp
		message(Auto set TEMPDIR = $${TMPDIR})
	}
}else{
	TMPDIR = $$TEMPDIR
}


#=========== Destination directory ========
isEmpty(DESTDIR){
	DESTDIR = ./
	contains(TEMPLATE, lib){
		DESTDIR = ./lib
	}else{
		DESTDIR = ./build
	}
	message(Auto set DESTDIR = $${DESTDIR})
}

TMP_DIR = $$TMPDIR

#=========== Terget Name ========
CONFIG (debug, debug|release) {
	contains(TEMPLATE, lib){
		TARGET = $$qtLibraryTarget($$TARGET)
	}else{
		TARGET  	= $$join(TARGET,,,.d)
	}
	OBJECTS_DIR = $${TMP_DIR}/debug
	# Console added in debug mode
	CONFIG 	   += console
}else{
	OBJECTS_DIR = $${TMP_DIR}/release
}

#=========== Std pathes ========
UI_DIR      = $${TMP_DIR}/uic
MOC_DIR     = $${TMP_DIR}/moc
RCC_DIR		= $${TMP_DIR}/rcc

#=========== build all if debug_and_release ========
contains(CONFIG, debug_and_release) {
	CONFIG 	   += build_all
}


#================== HARDCODED NAMES ===============
contains(HARDCODED, target) {
	TARGETTMP = '\\"$${TARGET}\\"'
	DEFINES  += TARGET=\"$${TARGETTMP}\"
}

contains(HARDCODED, translationdir) {
	TRDIR_TMP = '\\"$${TRDIR}\\"'
	DEFINES  += TRDIR=\"$${TRDIR_TMP}\"

}

#=================== DEBUG PRI ======================
!contains(DEBUGCONFIG, false){
	message("If you no need debug pri-file, then write next: DEBUGCONFIG = false")
	message(CONFIG = $${CONFIG})
	message(DESTDIR=$${DESTDIR})
	message(TARGET=$${TARGET})
	message(TMPDIR=$${TMPDIR})
	message(OBJECTS_DIR=$${OBJECTS_DIR})
	message(INCLUDEPATH = $${INCLUDEPATH})
	message(QMAKE_LIBDIR = $${QMAKE_LIBDIR})
	message(LIBS = $${LIBS})
	!isEmpty(HARDCODED){
		message(HARDCODED = $${HARDCODED})
		message(DEFINES = $${DEFINES})
	}	
	message(===================================)
}