#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string is_suffix) {
    if(is_suffix.size() > my_string.size()) return 0;
    
    // 실제 접미사인지 확인
    if(my_string.rfind(is_suffix) == (my_string.size() - is_suffix.size())){
        return 1;
    }
    return 0;
}