# wikiLYNX

A simple browser app made using Qt C++ to play wikipedia speedruns the right way. The project was initially made for the wikiLYNX event conducted by [@jonesrison](https://jonesrison.github.io) at RSET, Ernakulam, Kerala. Documentation is being updated.

## Introduction

### Wikipedia Speed-runs

Wikipedia, one of the world's largest online encyclopedia is sort of a universe of hyperlinks. Deviating from a main article we were supposed to research for our assignment/project, to an article completely different from our initial plans is not an uncommon experience. This experience slowly developed into game of Wikipedia speedruns. The player will be given an initial Wikipedia article from which one should find another article, perhaps completely unrelated to the initial topic, only through hyperlinks in the page.
This game though not probably recognised by any international organisation, is commonly known to folks among social media as Wikipedia Speedrun. The first one to reach, will be the winner!

### wikiLYNX Game Browser

Now a game must have rules! Though the game is not really documented by any Internation Organisation, we have formulated a set of rules we believe is the fundametal aspect of playing the game the right way. Some of these rules can still be disabled in this app, however we apply these rules by default. wikiLYNX Game Browser implements these rules and gives you a game field to play the game with your friends. The app is a simple C++ app based on Qt WebEngine.
If one happens to be someone interested in the game, one is invited to play the game and contribute to the development of this project.

### How to Play

Each level in our game systems consists of a some checkpoints. Your initial article will the first checkpoint. You are tasked with navigating to the next checkpoint through the hyperlinks on the page. After reaching the first checkpoint, you should navigate to the next checkpoint. You are not allowed to skip checkpoints. You can see your next checkpoint on the status bar below the browser or on the Checkpoints Dialog. Each level has a predefined timer. The game ends abrubtly when the timer ends. For competing with your friends, you can use the `Time Taken` field to declare the winner. Time Taken denotes the time taken by the player to finish the level from start till the end. If a player is unable to reach the last checkpoint, the `Time Taken` field denotes the time taken to reach the last checkpoint.
We have included some interesting levels by default. You can add your own levels in the `Edit Level` option in settings. You can also export your levels as a JSON file to share it with your friends. Download more levels from https://archive.pcland.co.in/DAWN/Projects/wikiLYNX/levels. To get to know the game, get started with the level `flyingduck`.

## Installation Instructions

The app is available for Windows and Linux. One was unable to port the app to Android since Qt Webengine is still not available for Android. Qt Webview is deprecated. To see all available installation files, check [DAWN Public Archives](https://archive.pcland.co.in/DAWN/Projects/wikiLYNX). All project files from DAWN are hosted here.

### Windows

wikiLYNX Browser is available as an installation for Windows 10 and above. Download the online installer from [here](https://github.com/flamboyantpenguin/wikiLYNX/releases/latest/download/wikiLYNX_win_installer_amd64.exe). You can update wikiLYNX using the MaintenanceTool from Start Menu.

| Platform                                                                                                                 | Availability | System Architecture |
| -------------------------------------------------------------------------------------------------------------------------|------------- | --------------------|
| [Windows 10/11](https://github.com/flamboyantpenguin/wikiLYNX/releases/latest/download/wikiLYNX_win_installer_amd64.exe) |      ☑️      |  amd64              |
| Windows 8.1                                                                                                              |      ❎      |  NULL               |
| Windows 7                                                                                                                |      ❎      |  NULL               |

Please feel free to let me know if you can help me build wikiLYNX for Windows 7 and 8.1.

### Linux

wikiLYNX is available for Debian, RPM and Arch Linux users. You can download the DEB and RPM files from GitHub releases page or from [DAWN Public Archives](https://archive.pcland.co.in/DAWN/Projects/wikiLYNX). wikiLYNX is available on AUR for Arch Linux users.

| Distribution                                                                                                          | Availability | Recommended Version     | System Architecture |
| --------------------------------------------------------------------------------------------------------------------- |------------- | ------------------------| --------------------|
| [Ubuntu (Debian)](https://github.com/flamboyantpenguin/wikiLYNX/releases/latest/download/wikiLYNX_1.2.6-0_amd64.deb)  |      ☑️      | 22.04 LTS or above      |  amd64              |
| [Fedora (RPM)](https://github.com/flamboyantpenguin/wikiLYNX/releases/latest/download/wikilynx-1.2.6-0.fc40.x86_64.rpm)     |      ☑️      | 40           |  amd64              |
| [Arch Linux (AUR)](https://aur.archlinux.org/packages/wikilynx)                                                       |      ☑️      | Built from source (AUR) |  any                |

#### Ubuntu (Debian)

Download deb from [here](https://github.com/flamboyantpenguin/wikiLYNX/releases/latest/download/wikilynx_1.2.6-0_amd64.deb).

To install, open it with Software in GNOME or Discover in KDE or any other software manager. To install using `apt` in cli, run the command

```bash
sudo apt install ./wikilynx_1.2.6-0_amd64.deb
```

wikiLYNX will be soon available for Debian as a private repository.

#### Fedora (RPM)

Download rpm from [here](https://github.com/flamboyantpenguin/wikiLYNX/releases/latest/download/wikilynx-1.2.6-0.fc40.x86_64.rpm).

To install it, open it with a support package manager or run the command =

```bash
sudo dnf install ./wikilynx-1.2.6-0.fc40.x86_64.rpm
```

You can also install by adding DAWN repository

```bash
sudo dnf config-manager --add-repo https://repo.pcland.co.in/rpm/dawn.repo
sudo dnf install wikilynx
```

#### Arch Linux (AUR)

Install using `yay` or any other `AUR` helper.

##### yay

```bash
yay -S wikilynx
```

##### makepkg

```bash
git clone https://aur.archlinux.org/packages/wikilynx
cd wikilynx
makepkg -si
```

#### Build from Source

You can also install the app by building from source using cmake.

Prerequisites: cmake, qt6-webengine-dev

```bash
git clone https://github.com/flamboyantpenguin/wikilynx
cd wikilynx/wikiLYNX
cmake .
make
sudo make install
```

### macOS

Currently, wikiLYNX is not available for macOS. One is invited to raise suggestions on how the app can be packaged for macOS users.

## Development

Coming soon...
