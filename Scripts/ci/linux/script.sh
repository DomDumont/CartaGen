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
LINUXDEPLOYQT=`pwd`/linuxdeployqt

# Location of the source tree
SOURCEDIR=`pwd`/Src

# Location to build PatternPaint
BUILDDIR='build-dist-linux'



################## Build CartaGen ##########################
mkdir -p ${BUILDDIR}
pushd ${BUILDDIR}

${QMAKE} ${SOURCEDIR}/CartaGen.pro \
    -r \
    -spec linux-g++

#${MAKE} clean
${MAKE} -j6

popd



################## Package using linuxdeployqt #################

pushd ${BUILDDIR}


# icns2png ${SOURCEDIR}/app/images/patternpaint.icns -x
# cp patternpaint_256x256x32.png patternpaint.png

cp ${SOURCEDIR}/CartaGen.icns ./
cp ${SOURCEDIR}/CartaGen.png ./
cp ${SOURCEDIR}/CartaGen.desktop ./


# TODO: this should be done automagically though the qt build tools?

# mkdir -p app/lib
# cp libblinky/libblinky.so.1 app/lib

unset LD_LIBRARY_PATH # Remove too old Qt from the search path; TODO: Move inside the linuxdeployqt AppImage

PATH=${QTDIR}/bin:${PATH} ${LINUXDEPLOYQT} CartaGen -bundle-non-qt-libs
PATH=${QTDIR}/bin:${PATH} ${LINUXDEPLOYQT} CartaGen -appimage

#tar -cjf CartaGen-x86_64_${VERSION}.tar.bz2 CartaGen-x86_64.AppImage
mkdir -p Image
pushd Image
cp ../CartaGen-x86_64.AppImage ./
popd
popd