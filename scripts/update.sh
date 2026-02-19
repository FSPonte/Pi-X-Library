sudo -l

echo "\n\tUpdating the package index"
sudo apt update

echo "\n\tInstalling available upgrades"
sudo apt full-upgrade -y

echo "\n\tRemoving unused dependency packages"
sudo apt autoremove -y

echo "\n\tFixing broken dependencies"
sudo apt install -f

echo "\n\tRemoving package cache"
sudo apt autoclean