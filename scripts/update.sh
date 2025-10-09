#!/bin/sh

sudo -l

echo "\n\tRemoving unused dependency packages"
sudo apt autoremove -y

echo "\n\tFixing broken dependencies"
sudo apt install -f

echo "\n\tUpdating the package index"
sudo apt update

echo "\n\tInstalling available upgrades"
sudo apt full-upgrade -y

sudo apt clean
