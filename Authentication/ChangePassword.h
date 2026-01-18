#ifndef CHANGEPASSWORD_H
#define CHANGEPASSWORD_H

class ChangePassword{
    private:
    std::string username;
    std::string oldPassword;
    std::string newPassword;
    public:
        void changePassword();
};

#endif