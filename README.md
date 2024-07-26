# AMD Desktop Config

## Jump Install Network Connections Guide < if haven't "Enter Without Net" Option >

when on network selection page > Shift+F10 > input "oobe\BypassNRO.cmd" > Windows will auto restart > "I haven't Internet Connections" > "Continue With Restricted Settings" > u can create local account now

## Basic Settings

### Necessary Drivers

AMD Auto-select Program stand last(need net connection)

### Windows update

### Power Plan

Settings > Power Plan > Ultimate<br>
Settings > Power Plan > Screen and sleep > all check "Never"

### Config of 5800X3D (MSI Motherboard)

1.Advanced > Settings > Advanced > PCIe/PCI Subsystem Settings > Re-Size BAR Support -> "enabled" (need mass GPU mem)

2.Advanced > Settings > Security > Trusted Computing > AMD fTPM switch -> "disabled"

3.OC > OC Explore Mode->[Expert] > Advanced CPU Configuration > Kombo Strike->[3] > AMD CBS > Global C-state Control->[disabled] (CPPC and CPPC Preferred Cores can disable for stability,enable for high r23 points)

4.OC > CPU Offset Voltage(-)->[0.0625V]

### Set "This PC" as start page

File Explorer > ··· > Options > Opens File Explorer To > check "This PC"<br>
File Explorer > ··· > Options > Privacy > all uncheck

### Category Rule

Sort > Date Modified

### Download Necessary Applications

#### Page Download

[Clash Verge](https://github.com/clash-verge-rev/clash-verge-rev)<br>
[Google Chrome](https://www.google.com/chrome/)<br>
Optimizer<br>
Win11EZToUse<br>
Dim2Clear<br>
Windows Cursor Enhancement<br>
EhPG 小說下載器<br>
[图吧工具箱](https://www.tbtool.cn/)<br>

#### 2 download

[7-zip](https://www.7-zip.org/download.html)<br>
[MSIAfterBurner](https://www.msi.com/Landing/afterburner/graphics-cards)<br>
[Logitech G Hub](https://www.logitechg.com/en-us/innovation/g-hub.html)<br>
[Voicemeeter](https://voicemeeter.com/)<br>
[枫叶工具箱](https://winmoes.com/tools/12948.html)<br>
[ContextMenuManager](https://github.com/BluePointLilac/ContextMenuManager)<br>
[Twinkle Tray](https://twinkletray.com/)<br>
[TranslucentTB](https://github.com/TranslucentTB/TranslucentTB)<br>
[singlefile](https://github.com/gildas-lormeau/SingleFile)<br>
[qbittorrent](https://www.fosshub.com/qBittorrent.html)<br>
[Lyricify4](https://github.com/WXRIW/Lyricify-App)<br>
[LANDrop](https://landrop.app/#downloads)<br>
[Steam](https://store.steampowered.com/about/)<br>
[Steam++](https://steampp.net/)<br>
[Epic](https://store.epicgames.com/en-US/download)<br>
[Telegram Desktop](https://telegram.org/)<br>
[Video Converter](https://handbrake.fr/downloads.php)<br>
[ImageGlass](https://github.com/d2phap/ImageGlass)<br>
[Magpie](https://github.com/Blinue/Magpie?tab=readme-ov-file)<br>
[Spotify](https://www.spotify.com/us/download/other/)<br>
[LockHunter](https://lockhunter.com/download.htm)<br>
[File Shredder](https://www.fileshredder.org/)<br>
[Bandizip](https://en.bandisoft.com/bandizip/)<br>
Start11<br>
GlassWire<br>
playnite<br>
Bulk Crap Uninstaller<br>
SmoothScroll Chrome Extension<br>
Advanced Font Settings Chrome<br>
Extensionq<br>

### Block Windows Update

Win+R > regedit > cd "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\WindowsUpdate\UX\Settings" > Right click > New > DWORD(32) > rename as "FlightSettingsMaxPauseDays" > open > Decimal-5000
open "Windows Update" > select pause date

### Privacy And Security Settings > OFF

### Notification > OFF

### Remove OneDrive Icon

Win+R > regedit > Ctrl+F > "018D5C66-4533-4307-9B53-224DE2ED1FE6 > u can see a DWORD(32) named "System.IsPinnedToNameSpaceTree" > change Hex from 1 to 0 > Restart File Explorer

### Storage Purify

Settings > Storage > open "Storage Sense"

### Keyboard Input

Settings > Time&Language > Typing > Advanced Keyboard Settings > Input Language Hotkey > Change Key Sequence > "Switch Input Language"->"Left Alt+Shift" and "Switch Keyboard Layout"->"Not Assigned"

### Windows Cursor Replace

### Fix Chrome Display Bugs

1.url open "chrome://flags/#use-angle" > change box to "D3D11on12","OpenGL" or "D3D9"<br>

### Close Heterogeneous Thread Scheduling

1.CMD execute "powercfg -attributes SUB_PROCESSOR 93b8b6dc-0698-4d1c-9ee4-0644e900c85d -ATTRIB_HIDE" and "powercfg -attributes SUB_PROCESSOR bae08b81-2d5e-4688-ad6a-13243356654b -ATTRIB_HIDE"<br>
2.Win+R > Control > Power Options > Change Plan Settings > Change Advanced Power Settings > Processor Power Management > change "Heterogeneous Thread Scheduling Policy" and "Heterogeneous Short running Thread Scheduling Policy" to "All Processor"

## Change-Anytime Config After Status

### Memory OC <Ref. value>

| Clock                | Voltage | TRC | TRFC |
| -------------------- | ------- | --- | ---- |
| 3200(13-18-18-18-36) | 1.45V   | 70  | 500  |
| 3400(13-18-18-18-36) | 1.45V   | 75  | 540  |
| 3600(14-19-19-19-38) | 1.45V   | 80  | 560  |
| 3800(15-20-20-20-40) | 1.45V   | 80  | 580  |
| 4000(16-21-21-21-42) | 1.45V   | 90  | 600  |

Trc 90
TrrdS 4
TrrdL 6
Tfaw 16
Twtrs 4
TwtrL 8
Twr 16
Trdrdscl 4
Twrwrscl 4
TRFC 600
Trtp 8

### 5800X3D r23 Ref.

| Single | 1465 |
| ------ | ---- |

| Multi | 14676 (15308) |
| ----- | ------------- |

### Customize Logitech G Hub install location

1.if we want install the hub in `D:\Program file`.We create a directory named `D:\Program file\LGHUB`under repository D.<br>
2.open powershell in administrator mode.<br>
3.goto root folder where logitech want to install:`cd 'C:\Program File`<br>
4.create symlink

```
New-Item -ItemType SymbolicLink -Path 'C:\Program Files\LGHUB\' - Value 'D: \Program Files\LGHUB\'
```

5.now run the .exe<br>
6.confirm the app installed there in rep C<br>
