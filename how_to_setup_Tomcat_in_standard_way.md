# How to setup Tomcat in standard way

**Author** `Black Welt`

> If you encounter formatting problems on the web page, plz use local reader to load it.

Unexpectedly I started Web rehabilitation by a quest. :innocent:<br>
Most of the problems that novices have when installing Tomcat are caused by irresponsible strategies which 'we-media made' on search engines.<br>
I found most Q&A dealing with getting the NetBeans IDE to talk to the Apache Tomcat servlet container are seem to be out of date or involve extraneous steps.<br>
##Preparation
Indeed, getting Tomcat connect to NetBeans is fairly simple but not visible.<br>
###brew way
Another quite simple method is to use Homebrew, input `brew install tomcat` on Terminal, the program will install and config automatically.<br>
###Custz way
Before config, you may need to customize the installation to get Tomcat, check Tomcat -v, Java EE edition, and runtime lib.
![Tomcat_version](/assets/Tomcat_version.png 'Tomcat Version')<br>
You should download `.gz` file on Mac, if ur Windows user, just get win-version below.<br>
![access_way](/assets/access_way.png 'which patch')<br>

####File permissions
Be sure your copy of Tomcat can run in `/Downloads` folder. The permissions by default usually do not allow execution, at least in my experience on a Mac, you may get such error:<br>

    systemd[1]: tomcat.service: Failed to execute command: Permission denied
    systemd[1]: tomcat.service: Failed at step EXEC spawning /opt/tomcat/bin/startup.sh: Permission denied

So we need get permissions, and if you are a Unix whiz, you can do so in the CLI.The rest of us use the [BatChmod App](https://batchmod.en.softonic.com/mac).<br>
Here we turn on all the checkboxes except `Clear xattrs`.<br>
![Screenshot 2024-02-29 at 1.16.40 PM](/assets/Screenshot%202024-02-29%20at%201.16.40 PM.png "Permissions")<br>

> Permission denial is a rare probability event ( if your mac is configured with a development environment), please do not use **sudo** and **777** commands at will.

####Config
Verify that Tomcat can run by executing the **startup.sh** file under Tomcat’s `bin` folder, or use CLI input `./startup.sh`. <br>
![Screenshot 2024-02-29 at 1.30.14 PM](/assets/Screenshot%202024-02-29%20at%201.30.14 PM.png "Startup CLI")<br>
Access your web browser to `http://localhost:8080/` to see a Tomcat page.<br>
![Screenshot 2024-02-29 at 1.30.24 PM](/assets/Screenshot%202024-02-29%20at%201.30.24 PM.png "Test page")<br>
Then run **shutdown.sh** file or `./shutdown.sh`to quit Tomcat.<br>
Congratulations! :notes:<br>
Now we have completed the basic configuration.<br>
##Define a Server in NetBeans
Of course, this requires you to install the **NetBeans** on your Mac, but version 20 is almost automatically configured, so we skip it here.<br>
In the explore pane, context-click on the `Servers` item, choose `Add server`.<br>
![Screenshot 2024-02-29 at 2.14.07 PM](/assets/Screenshot%202024-02-29%20at%202.14.07 PM.png "add server")<br>

###Choose Server
In the dialog that appears, choose `Apache Tomcat or TomEE`. Type a name to be displayed in NetBeans list of **Servers**. I suggest typing `Tomcat + version` for distinguish.<br>
![Screenshot 2024-02-29 at 2.20.37 PM](/assets/Screenshot%202024-02-29%20at%202.20.37 PM.png)<br>

> I already added so there's a red message.

###Find Tomcat Location
Select the `Server Location` -> `Browse` button, and choose where your Tomcat folder. I recommended storing under `/Library` folder.
![Screenshot 2024-02-29 at 2.30.50 PM](/assets/Screenshot%202024-02-29%20at%202.30.50 PM.png)<br>
This may happened:<br>
![Screenshot 2024-02-29 at 2.33.24 PM](/assets/Screenshot%202024-02-29%20at%202.33.24 PM.png)<br>
Please try to authorize again, or move the file to a place where you have full access permission.<br>
###Deployment Location
Turn on the `Use Private Configuration Folder(Catalina Base)` checkbox.<br>
We need to choose a folder where we want Tomcat to do its work, keep its temporary files, keep its logs, and place the installed copy of your web app when you run from within NetBeans. Recommended create one.<br>
For its bundled version of Tomcat(old version), NetBeans uses a folder nested in `~/Library/Application Support`. **The folder’s location can be anywhere**. But I tend to create a folder in home folder with a nested folder for each version of Tomcat, `~/Apache-Tomcat-Netbeans/11.0.0_M17/` for example. Unix & Java tend to get cranky about spaces in file paths, so suggested hyphens or `_` rather than spaces in those folder names.<br>
###Manage User Panel
Make up a user name and password to be used as a Tomcat **manager** to startup and shutdown Tomcat. Be sure to check the `Create user if it does not exist` checkbox.<br>
![Screenshot 2024-02-29 at 2.57.37 PM](/assets/Screenshot%202024-02-29%20at%202.57.37 PM.png)<br>
Now you have a new Tomcat server defined within NetBeans.<br>
![Screenshot 2024-02-29 at 2.58.57 PM](/assets/Screenshot%202024-02-29%20at%202.58.57 PM.png)<br>
###And One More Thing...
If you added multi servers, u can GO your project’s `Properties` dialog, set `Build` -> `Run` -> `Server`to adjust your target server.<br>
![Screenshot 2024-02-29 at 3.03.43 PM](/assets/Screenshot%202024-02-29%20at%203.03.43 PM.png)<br>
##Problems you may encounter
When you visit localhost, `Server Status` and `Manager App` use the same config, `Host Manager` is another.<br>
![Screenshot 2024-02-29 at 3.10.50 PM](/assets/Screenshot%202024-02-29%20at%203.10.50 PM.png)<br>

###Enable/disable control panel
The access to console page is not enabled, generally the redirect page reports the following error:<br>
`You are not authorized to view this page. If you have not changed any configuration files, please examine the file conf/tomcat-users.xml in your installation. That file must contain the credentials to let you use this webapp.`<br>
**Solution:**<br>
Add username and password in `/Users/<your mame>/Library/Tomcat/conf/tomcat-users.xml`, label `<tomcat-users>`.<br>
For instance, we add an account with the username `Black_Welt` and password `040103`. Displayed as:<br>
![Screenshot 2024-02-29 at 3.23.28 PM](/assets/Screenshot%202024-02-29%20at%203.23.28 PM.png)<br>
The `manager-gui` is used to log in to `Server Status` and `Manager App`, while the `admin` is used in `Host Manager`.<br>
After the addition is completed, restart Tomcat and you can log in to the console with the added username and password.<br>
To disable the console, just comment out or delete all `users` under the `<tomcat-users>`tag in `conf/tomcat-users.xml`.<br>
###Allow/deny remote machine access to control panel
Even though the `username` and `password` are added, Tomcat by default only allows login to the panel from local machine.<br>
Unallowed IP access to the console often be redirected and reports the following error:<br>
`By default the Host Manager is only accessible from a browser running on the same machine as Tomcat. If you wish to modify this restriction, you'll need to edit the Manager's context.xml file.`<br>
**Solution:**<br>
To allow access, GO `webapps/manager/META-INF/context.xml` and find the end:<br>
![Screenshot 2024-02-29 at 3.39.44 PM](/assets/Screenshot%202024-02-29%20at%203.39.44 PM.png)<br>
Comment it out to indicate that all IPs are accessible and then restart.<br>
![Screenshot 2024-02-29 at 3.41.56 PM](/assets/Screenshot%202024-02-29%20at%203.41.56 PM.png)<br>
If necessary, you can also imitate and modify the restricted IP.<br>
##Last Attentions
The values, labels and even files in the aforementioned configuration may change with version. If you choose a configuration that others say is feasible, it will not take effect when you config it yourself.<br>
In fact, the redirect page after accessing without permission has given the best process and method.<br>

**THE END**
![IMG_6202](/assets/IMG_6202.JPG)
