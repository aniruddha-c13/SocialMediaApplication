#include "User.h"

using namespace std;

long long int User::userID = 1;

// Initialize User object and increment static id
User::User(string iname, string ipassword)
{
    name = iname;
    passwd = ipassword;
    id = userID++;
}

// User posts are created, allocated and maintained in User objects
Post* User::createpost(long long int iuserid, long long int iyear, string icontent)
{
    Post *curpost = new Post(iuserid, iyear, icontent);
    // Store pointers to user posts
    myposts.push_back(curpost);
    return curpost;
}

// Method to follow given user
void User::followuser(User *iuser)
{
    // Store pointers to following users
    followingusers.push_back(iuser);
}

// Method to unfollow given user
void User::unfollowuser(User *iuser)
{
    vector<User *>::iterator it;
    for(it = followingusers.begin(); it != followingusers.end(); it++)
    {
        if((*it) == iuser)
        {
            // Remove the followed user
            followingusers.erase(it);
            return;
        }
    }
    // Print error if the user being unfollowed does not exist in followingusers list of this user
    cout << "Invalid Input" << endl;
}

// Method to get id attribute
long long int User::getID()
{
    return id;
}

// Method to get name attribute
string User::getname()
{
    return name;
}

// Method to get passwd attribute
string User::getpasswd()
{
    return passwd;
}

User::~User()
{
    // Delete user posts created and allocated in User objects
    for(auto curpost : myposts)
        delete curpost;
    // Delete pointers to user posts
    myposts.clear();
    // Delete pointers to following users
    followingusers.clear();
}

// Friend function to overload output stream insertion operator for user class
ostream& operator<< (ostream& os, const User& user)
{
    // Print the user details in required format
    os << "User Id: " << user.id << ", User Name: " << user.name << ", Number of Posts: " << user.myposts.size() << ", Following Count: " << user.followingusers.size();
    return os;
}

