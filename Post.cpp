#include "Post.h"

using namespace std;

long long int Post::postID = 1;

// Initialize Post object and increment static id
Post::Post(long long int iuserID, long long int iyear, string icontent)
{
    userID = iuserID;
    content = icontent;
    year = iyear;
    id = postID++;
}

// Method to get userID attribute
long long int Post::getuserID()
{
    return userID;
}

// Method to get id attribute
long long int Post::getID()
{
    return id;
}

// Friend function to overload output stream insertion operator for Post class
ostream& operator<< (ostream& os, const Post& post)
{
    // Print post details in the required format
    os << "Post Id: " << post.id << ", User Id: " << post.userID << ", Year: " << post.year << ", Post Content: " << post.content;
    return os;
}

