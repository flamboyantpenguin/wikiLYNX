# wikiLYNX 

A simple browser app made using Qt C++ to play wikipedia speedruns the right way. The project was initially made for the wikiLYNX event conducted by [@jonesrison](https://github.com/jonesrison) at RSET, Kerala. Documentation is under maintenance.

## Introduction

Wikipedia, one of the world's largest online encyclopedia is sort of a universe of hyperlinks. Deviating from a main article we were supposed to research for our assignment/project, to an article completely different from our initial plans is not an uncommon experience. This experience slowly developed into a game. The player will be given an initial Wikipedia article from which one should find another article, perhaps completely unrelated to the initial topic, only through hyperlinks in the page. This game though not probably recognised by any international organisation, is commonly known to folks among social media as Wikipedia Speedrun.
wikiLYNX is a game browser designed to let everyone play this game the right way. The browser let's you play the game with certain rules in place making this an oppurtunity to test oneself among one's acquaintances. The app is a simple C++ app based on Qt WebEngine. If one happens to be someone interested in the game, one is invited to play the game and contribute to the development of this project.
To get started, enter your name and select a level of your choice. Once the game starts, you can see your next checkpoint on the status bar below. You have to navigate to the specified Wikipedia page through the hyperlinks. Keyboard is disabled and you're not allowed to access reference links by default. To get to know the game, get started with the level `flyingduck`. 

## Installation Instructions

I have built the app for Windows and Linux. I'm unable to port this to Android since Qt Webengine is still not available for Android. Qt Webview is deprecated. To see all available installation files, check [here](https://archive.pcland.co.in/DAWN/Projects/wikiLYNX).

### Windows

wikiLYNX Browser is available as an installation for Windows 10 and above. Download the online installer from [here](https://github.com/flamboyantpenguin/wikiLYNX/releases/latest/download/wikiLYNX_win_installer_amd64.exe). You can update wikiLYNX using the MaintenanceTool from Start Menu.

| Platform                                                                                                                 | Availability | System Architecture |
| -------------------------------------------------------------------------------------------------------------------------|------------- | --------------------|
| [Windows 10/11](https://github.com/flamboyantpenguin/wikiLYNX/releases/latest/download/wikiLYNX_win_installer_amd64.exe) |      ☑️      |  amd64              |
| Windows 8.1                                                                                                              |      ❎      |  NULL               |
| Windows 7                                                                                                                |      ❎      |  NULL               |

Please feel free to let me know if you can help me build wikiLYNX for Windows 7 and 8.1. 

### Linux

wikiLYNX is available as a binary package for Debian and RPM. The package is built from source for Arch Linux users (AUR). 

| Distribution                                                                                                          | Availability | Recommended Version     | System Architecture |
| --------------------------------------------------------------------------------------------------------------------- |------------- | ------------------------| --------------------|
| [Ubuntu (Debian)](https://github.com/flamboyantpenguin/wikiLYNX/releases/latest/download/wikiLYNX_1.2.0-5_amd64.deb)  |      ☑️      | 22.04 LTS or above      |  amd64              |
| [Fedora (RPM)](https://github.com/flamboyantpenguin/wikiLYNX/releases/latest/download/wikiLYNX_1.2.0-5_amd64.rpm)     |      ☑️      | 38 or above             |  amd64              |
| [Arch Linux (AUR)](https://aur.archlinux.org/packages/wikilynx)                                                       |      ☑️      | Built from source (AUR) |  any                |

#### Ubuntu (Debian)

Download deb from [here](https://github.com/flamboyantpenguin/wikiLYNX/releases/latest/download/wikiLYNX_1.2.0-5_amd64.deb).

To install, open it with Software in GNOME or Discover in KDE or any other software manager. To install using `apt` in cli, run the command 

```bash
sudo apt install ./wikiLYNX_1.2.0-5_amd64.deb
```

wikiLYNX will be soon available on for Ubuntu as a ppa and for Debian as a private repository. 

#### Fedora (RPM) 

Download rpm from [here](https://github.com/flamboyantpenguin/wikiLYNX/releases/latest/download/wikiLYNX_1.2.0-5_amd64.rpm).

To install it, open it with a support package manager or run the command 

```bash
sudo dnf install ./wikiLYNX_1.2.0-5_amd64.rpm
```

#### Arch Linux (AUR)

Install using `yay` or any other `AUR` helper. 

##### yay

```bash
yay -S wikilynx
```

### macOS

Currently, wikiLYNX is not available for macOS. One is invited to open suggestions on how the app can be packaged for macOS users.

## Development

Coming soon...
