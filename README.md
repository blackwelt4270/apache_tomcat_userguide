# AMD Desktop Config

## Jump Start Network Connections < if haven't Enter Without Net Option >

when on network selection page > Shift+F10 > input "oobe\BypassNRO.cmd" > Windows will auto restart > "I haven't Internet Connections" > "Continue With Restricted Settings" > u can create local account now

## Basic Settings

### Necessary Drivers

### Power Plan

Settings > Power Plan > Ultimate<br>
Settings > Power Plan > Screen and sleep > all check "Never"

### Set "This PC" as start page

File Explorer > ··· > Options > Opens File Explorer To > check "This PC"<br>
File Explorer > ··· > Options > Privacy > all uncheck

### Category Rule

Sort > Date Modified

### Download Necessary Applications

#### Github Page Download

[Clash Verge](https://github.com/clash-verge-rev/clash-verge-rev)<br>
Optimizer<br>
Windows11 轻松设置<br>
Dim2Clear<br>
Windows Cursor Enhancement<br>
[图吧工具箱](https://www.tbtool.cn/)<br>

#### Google 2 download

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
Aim Lab<br>

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

Settings > Time And Language > Typing > Advanced Keyboard Settings > Input Language Hotkey > Switch keyboard layout > check "Undistributed"

### Windows Cursor Replace

### Fix Chrome Display Bugs

1.url open "chrome://flags/#use-angle" > change box to "D3D11on12"<br>
2.url open "chrome://flags/#use-angle" > change box to "OpenGL"<br>
3.url open "chrome://flags/#use-angle" > change box to "D3D9"<br>

### Close Heterogeneous Thread Scheduling

1.CMD execute "powercfg -attributes SUB_PROCESSOR 93b8b6dc-0698-4d1c-9ee4-0644e900c85d -ATTRIB_HIDE" and "powercfg -attributes SUB_PROCESSOR bae08b81-2d5e-4688-ad6a-13243356654b -ATTRIB_HIDE"<br>
2.Win+R > Control > Power Options > Edit Plan Settings > Change Advanced Power Settings > Processor Power Options > change "Heterogeneous Thread Scheduling Policy" and "Heterogeneous Short-run Thread Scheduling Policy" to "All Processor"

## Change-Anytime Config After Status
