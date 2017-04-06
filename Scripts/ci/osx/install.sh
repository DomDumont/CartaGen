
wget https://dl.itch.ovh/butler/darwin-amd64/head/butler
chmod +x butler

brew update
brew install qt5
chmod -R 755 /usr/local/opt/qt5/*

export QTDIR=/usr/local/opt/qt5