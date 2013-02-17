2/16/2012

sc2helper is a small command line program that allows users to more 
easily copy UI and graphics settings between computers. Put it on a 
usb drive and use the get option to copy the connected computer's 
setting to the usb drive.  Use the put option to deliver the settings 
file to the game's default installation.

For Wings of Liberty, the default target is:
C:\Users\currentuser\Documents\StarCraft II

For Heart of the Swarm, the default target is:
C:\Users\currentuser\Documents\StarCraft II Beta

I have also included the source code should you wish to examine or change
it. The following should compile it with mingw on windows:
prompt>g++ SC2SetupHelper.cpp -o sc2helper.exe -m32

gl hf


prompt>sc2helper.exe version action [name]

version : wol, hots
action  : get, put

wol
-uses default Wings of Liberty directory for setting Variables.txt

hots
-uses default Heart of the Swarm directory for setting Variables.txt

get
-creates a local copy of Variables.txt

put
-writes local Variables.txt to default directory

name
-optional argument that allows user to specify a name for Variables.txt
-if the get option is being used, this names the local copy name.txt
-if the put option is being used, this copies name.txt into the games Variables.txt