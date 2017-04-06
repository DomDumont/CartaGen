#!/bin/bash

# Stop at any error
set -e

# Location of the QT tools
if [ -z ${QTDIR+x} ]; then
	echo "QTDIR not defined- please set it to the location containing the Qt version to build against. For example:"
	echo "  export QTDIR=~/Qt5.8.0/5.8/gcc_64"
	exit 1
fi

QMAKE=${QTDIR}/bin/qmake
MAKE=make
MACDEPLOYQT=${QTDIR}/bin/macdeployqt

# Location of the source tree
SOURCEDIR=`pwd`/Src

# Location to build PatternPaint
BUILDDIR='build-dist-osx'



################## Build CartaGen ##########################
mkdir -p ${BUILDDIR}
pushd ${BUILDDIR}

${QMAKE} ${SOURCEDIR}/CartaGen.pro \
    -r


#${MAKE} clean
${MAKE} -j6

popd



################## Package using macdeployqt #################

pushd ${BUILDDIR}



PATH=${QTDIR}/bin:${PATH} ${MACDEPLOYQT} CartaGen.app -always-overwrite -verbose=2
PATH=${QTDIR}/bin:${PATH} ${MACDEPLOYQT} CartaGen.app -dmg -no-plugins
ls

popd