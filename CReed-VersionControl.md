# Instructions

Update this document where indicated [look for the brackets!]. Replace text inside the brackets with your own information. For example: Course Name should be the name of this course, and not the generic words "Course Name".

<br>

## [COS1 <-- Replace all text in brackets ]

- **[ Corion Reed]**
- **[ August 8, 2026 ]**

This paper addresses some of the topic matter covered in research and activity this week. Be sure to include reference links below to the research and information you used to complete this assignment.

## Topic: Terminal

Professional developers use Terminal daily. It's essential to understand some fundamental commands to use the application.

Update the information below to demonstrate your knowledge on this topic.

**1. Using Terminal, there are essential commands to know.**

List the correct Terminal commands to do the actions listed below. Replace **CMD** with the correct command sequence. You can keep or enhance the brief description.

**The last bullet provides an example**.

- [ cls ]: Clear the Screen
- [ cd ]: Print the "Working Directory"
- [ dir ]: List files and folders
- [ dir /a ]: List files and folders, including invisible files
- [tree /f ]: List all files and folders, in human readable form
- [ cd Foldername ]: Change directory
- [ cd \ ]: Change directory, go to root directory
- [ cd %USERPROFILE% ]: Change directory and go to user home directory
- [ cd .. ]: Change directory, go up one folder level
- [ cd..\.. ]: Change directory, go up two folder levels
- [ cd %USERPROFILE%\Desktop ]: Change directory to my desktop!

**2. Using Terminal...**

**Folder Drop:** Try typing "cd" followed by a space, and then drag a folder into terminal and press return. Test this out and describe your results below.

[ Displayed the pathway to the file]

## Topic: Version Control & Git

Version control, also known as revision control, records changes to a file or set of files over time so that you can recall specific versions later. In this class, we are learning Git. Update the information below where indicated.

**1. There are three types of version control.**

[ **Local Version Control**- Stores file changes and its versions on your computer only.

  **Centralized Version Control**- Strores files on a central central server that others can access.
  
  **Distrubted Version Controls**- Gives every user a complete copy of the project and its history.]

**2. Using Terminal, there are also essential Git commands to know.**

List the correct Git commands to do the actions listed below in Terminal. Replace CMD with the correct command and keep or enhance the brief description.

- [ git clone <repository-url> ]: Clone a repository
- [ git config --globl user.name "Your name" ]: Set-up a global user name
- [ git config --global user.email "youremail@example.com ]: Set-up a global email address (to match my GitHub account email)
- [ git status ]: Shows the current state of your directory and staging area
- [ git add. ]: Add modified files to the next commit
- [ git commit -m ]: Make a commit with a new message
- [ git log ]: Show my commit history
- [ git help]: Show Git's help screen

**3. Connecting to GitHub using Terminal.**
HTTPS is the the correct way to connect to GitHub in this course. Describe how you connect to GitHub from Terminal using this protocol. What steps do you take?

[ 1. Open the GitHub repository, click the green **Code** button.
  1. select **HTTPS** and copy the *repository URL*.
  1. Open Terminal and navigate to the folder where I want the repository saved.
  1. Type *git clone* followed by the copied HTTPS URL, and the press Enter.
  ]

**4. Using .gitignore and Why it's Important**  
Most repositories contain a .gitignore file.

- What is the purpose of this file?
  <br>
  [to help prevent temporary, private, or unnecessary files from being included by telling Git which files it should not track or upload to the repository]

- What is the "**.DS_Store**" file and why would you want to ignore it?
  <br>
  [A hidden file created by MacOS to save folder display settings. It should be ignored because it is not part of the project, it may cause unnecessary changes in the repository]

- What other file or folder would you want to add to a .gitignore file and why?
  <br>
  [I would probably add the .vs/ folders becasue they contain temporary visual studio settings that are specific to my computer and others that are working on the project do not need them.]

<br>

# Reference Links

Replace the example references below with your own links and recommended resources. It is acceptable to provide multiple links for a single topic and to use material provided to you in this class. You are encouraged to link to your own independent research as well.

[ Research Summary: What resource(s) did you find most helpful this past week and why? ]

**Terminal Commands**  
[Site Address](https://learn.microsoft.com/en-us/windows-server/administration/windows-commands/windows-commands#c)

**Three Types of Version Control**  
[Site Address](https://git-scm.com/book/en/v2/Getting-Started-About-Version-Control.html)

**Git Commands**  
[Site Address](https://www.geeksforgeeks.org/git/git-cheat-sheet/)

**Connecting to GitHub using Terminal**  
[Site Address](https://docs.github.com/en/repositories/creating-and-managing-repositories/cloning-a-repository)

**Using .gitignore and Why it's Important**  
[Site Address](https://docs.github.com/en/get-started/getting-started-with-git/ignoring-files)
