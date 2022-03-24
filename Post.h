#ifndef __POST_H
#define __POST_H

#include <bits/stdc++.h>

using namespace std;

class Post
{
private:
    // Static id for Post objects
    static long long int postID;
    // Attributes
    // Post id
    long long int id;
    // ID of user that posted this post
    long long int userID;
    // Post contents
    string content;
    // Post year
    long long int year;
public:
    // Constructor
    Post(long long int iuserID, long long int iyear, string icontent);
    // Methods
    // Get method for user ID attribute
    long long int getuserID();
    // Get method for id attribute
    long long int getID();
    // Friend function to overload output stream insertion operator
    friend ostream& operator<< (ostream& os, const Post& post);
    // Destructor
    ~Post() {};
};

// Function to overload output stream insertion operator
ostream& operator<< (ostream& os, const Post& post);

#endif //__POST_H
