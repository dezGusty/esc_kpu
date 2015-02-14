# esc_kpu
Escape Key Pressing Utility

## How did this application came to be?
I bought a new laptop in 2015: an Asus ROG G751JT. A nice laptop, but with some quirks.

The one I found to be immediately the most annoying was the placement of a dedicated key for something called "Asus One click to record".
 
This seems to launch Nvidia's ShadowPlay application, which is an application that can capture gameplay, recording and streaming. 
This is something which I don't really use or need.

But I can (and do) accidentally press the Shadow Play key when I indend to press the ESC key

I tried deacticating that key, but I'm new with computers and I could not find out how to do it.
Other users on the Asus forums suggested replacing the launched application with a dummy executable, such as rundll32.exe without parameters.
This meant renaming the previous [ATKRecHelp.exe] application, in case you know, I actually need it at some point.

But replacing the launched application would resolve only half of the problem:
I would not launch an application I did not desire to launch.
But I would still not press the ESC key, which is what I would have wanted in the first place.

Luckily, it is possible to programatically insert key events and make it seem like the ESC key is pressed via the WinAPI.

## How to use it
Download the pre-built binaries or build the application yourself from source
(Currently only providing project files for Visual Studio 2013 Express).

Rename your old executable named "ATKRecHelp.exe" into something else (E.g. "ATKRecHelp_renamed.exe"
You would typically find this in: "c:\Program Files (x86)\ASUS\ATK Package\ATK Hotkey"

Copy the "esc_kpu.exe" to the location where "ATKRecHelp.exe" was.
Rename "esc_kpu.exe" to "ATKRecHelp.exe".

Now you can press the key accidentally and have it act like the Escape key.