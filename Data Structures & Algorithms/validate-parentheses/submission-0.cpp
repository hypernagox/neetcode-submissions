class Solution {
public:
    bool isValid(string s)
    {
        string stack; stack.reserve(s.size());
        for(const auto ch : s)
        {
            if(stack.empty())
            {
                stack.push_back(ch);
                continue;
            }
            bool flag = false;
            bool ok = false;
            switch (ch)
            {
                case ']':flag = stack.back() == '[';break;
                case ')':flag = stack.back() == '(';break;
                case '}':flag = stack.back() == '{';break;
                default: stack.push_back(ch); ok = true;
            }
            if(flag)stack.pop_back();
            else
            {
                if(!ok)return false;
            }
        }
        return stack.empty();
    }
};
