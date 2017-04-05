
sudo apt-get -y install qt58base qt58declarative qt58serialport

wget https://dl.itch.ovh/butler/linux-amd64/head/butler
chmod +x butler

wget -c https://github.com/probonopd/linuxdeployqt/releases/download/2/linuxdeployqt-2-x86_64.AppImage -O linuxdeployqt
chmod a+x linuxdeployqt

export QTDIR=/opt/qt58