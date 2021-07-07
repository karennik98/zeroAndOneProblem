#include <iostream>

#include <string>
#include <stack>

int zeroAndOne(const std::string& str) {
    std::stack<char> st;
    for(int i = 0; i < str.size(); ++i) {
        if(!st.empty()) {
            char ch = st.top();
            switch (ch) {
                case '*': {
                    st.push(str[i]);
                    break;
                }
                case '0': {
                    if(str[i] == '1') {
                        st.pop();
                    } else {
                        st.push(str[i]);
                    }
                    break;
                }
                case '1': {
                    if(str[i] == '0') {
                        st.pop();
                    } else {
                        st.push(str[i]);
                    }
                    break;
                }
            }
        } else {
            st.push(str[i]);
        }
    }
    return st.size();
}

int main() {
    std::string str1 = "111*000";
    std::string str2 = "10000101";
    std::string str3 = "111000";
    std::string str4 = "010101010";

    std::cout<<"zeroAndOne for "<<str1<<" -> "<<zeroAndOne(str1)<<std::endl;
    std::cout<<"zeroAndOne for "<<str2<<" -> "<<zeroAndOne(str2)<<std::endl;
    std::cout<<"zeroAndOne for "<<str3<<" -> "<<zeroAndOne(str3)<<std::endl;
    std::cout<<"zeroAndOne for "<<str4<<" -> "<<zeroAndOne(str4)<<std::endl;
    return 0;
}
