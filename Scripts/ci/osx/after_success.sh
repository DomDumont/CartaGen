ls
if [ "$TRAVIS_TAG" ]; then #not empty
./butler push ${BUILDDIR}/Image domdumont/cartagen:osx-"$TRAVIS_TAG"-alpha
fi