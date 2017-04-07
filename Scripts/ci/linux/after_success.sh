ls
if [ "$TRAVIS_TAG" ]; then #not empty
./butler push ${BUILDDIR}/Image domdumont/cartagen:linux-"$TRAVIS_TAG"-alpha
fi

