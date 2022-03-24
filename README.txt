README
======

=====================================================================================================================
Author: Aniruddha Chaudhari
=====================================================================================================================

1. Build command:
=================
$ make clean
rm -f SocialMediaApplication *.o
$ make SocialMediaApplication
g++ -Wall -g -o SocialMediaApplication main.cpp System.cpp User.cpp Post.cpp
$

2. Usage:
=========
$ ./SocialMediaApplication


3. Input format and Processing:
===============================

Input keywords and parameters are processed as mentioned below:

3.1 CREATE nameOfSystem
    On CREATE keyword, System object is created for given name [nameOfSystem].
3.2 SIGNUP usernameOfNewUserCreated passwordOfNewUserCreated
    On SIGNUP keyword, User object, with given name [usernameOfNewUserCreated] and password [passwordOfNewUserCreated], gets created (allocated) and maintained in System object.
3.3 SIGNIN userIdOfUserSigningIn passwordOfUserSigningIn
    On SIGNIN keyword, given user ID [userIdOfUserSigningIn] and password [passwordOfUserSigningIn] are validated and current system user is set.
3.4 SIGNOUT
    On SIGNOUT keyword, current system user is reset.

Each of following System object methods are exercised (as specified in the specifications file) for current system user.

3.5 FOLLOW usernameOfTheOneBeingFollowed
    On FOLLOW keyword, user to be followed, with given name [usernameOfTheOneBeingFollowed], is added to followingusers list in User object of current system user.
3.6 UNFOLLOW usernameOfTheOneBeingUnfollowed
    On UNFOLLOW keyword, user to be unfollowed, with given name [usernameOfTheOneBeingUnfollowed], is removed from followingusers list in User object of current system user.
3.7 POST YearOfPost ContentOfPost
    On POST keyword, new post, with given year [YearOfPost] and content [ContentOfPost - can contain spaces], is created (allocated) and maintained in posts list in User object of current system user.
    The new created post is returned back by createpost method of User object and is added in list of posts maintained in System object.
3.8 PRINTUSER userIdOfUserObject
    On PRINTUSER keyword, overloaded output stream insertion operator for user, with given ID [userIdOfUserObject], is invoked from printuser method of system.
    This is executed for user object corresponding to input user ID, irrespective of current system user.
3.9 PRINTPOST postIdOfPostObject
    On PRINTPOST keyword, overloaded output stream insertion operator for post, with given ID [postIdOfPostObject], is invoked from printpost method of system.
    This is executed for post object corresponding to input post ID, irrespective of current system user.
3.10 EXIT
     On EXIT, accumulated output is printed in appropriate format and destructors are invoked via "delete sys" in main.

Note:
- System object destructor deletes users in it's users lists as it created those.
- User object destructor deletes posts in it's myposts lists as it created those.

For all above functionality, appropriate error messages are printed according to error conditions.

4. Sample run:
==============

$ make clean
rm -f SocialMediaApplication *.o

$ make SocialMediaApplication
g++ -Wall -g -o SocialMediaApplication main.cpp System.cpp User.cpp Post.cpp

$ ./SocialMediaApplication
CREATE sma
SIGNUP user1 password1
SIGNUP user2 password2
SIGNIN user1 password3
SIGNOUT
SIGNIN user1 password1
FOLLOW user2
POST 2021 this is the first post
SIGNOUT
SIGNUP user3 password3
SIGNIN user2 password2
FOLLOW user1
UNFOLLOW user1
UNFOLLOW user1
POST 2020 this is the second post
SIGNOUT
PRINTUSER 1
PRINTUSER 2
PRINTUSER 3
PRINTUSER 4
SIGNUP user4 password4
PRINTUSER 4
SIGNOUT
POST 2022 this is the third post
PRINTPOST 1
PRINTPOST 2
PRINTPOST 3
EXIT
sma
Access Denied
Invalid Input
User Id: 1, User Name: user1, Number of Posts: 1, Following Count: 1
User Id: 2, User Name: user2, Number of Posts: 1, Following Count: 0
User Id: 3, User Name: user3, Number of Posts: 0, Following Count: 0
Invalid Input
User Id: 4, User Name: user4, Number of Posts: 0, Following Count: 0
Access Denied
Post Id: 1, User Id: 1, Year: 2021, Post Content: this is the first post
Post Id: 2, User Id: 2, Year: 2020, Post Content: this is the second post
Invalid Input
$

=====================================================================================================================

