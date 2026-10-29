class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        // vector<string> v;
        // for(int i=0;i<strs.size();i++){
        //     v.push_back(strs[i]);
        // }
        string comm="";
        int n=strs.size();
        string fstr=strs[0];
        string lstr=strs[n-1];
        for (int j = 0; j < strs[0].size(); j++) {
                if (fstr[j]==lstr[j]) {
                    comm+=fstr[j];   
                }else break;
            }
        return comm;
    }
};
static const bool __boost = []() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    return std::ios_base::sync_with_stdio(false);
    }();
const size_t BUFFER_SIZE = 0x6fafffff;
alignas(std::max_align_t) char buffer[BUFFER_SIZE];
size_t buffer_pos = 0;
void* operator new(size_t size) {
    constexpr std::size_t alignment = alignof(std::max_align_t);
    size_t padding = (alignment - (buffer_pos % alignment)) % alignment;
    size_t total_size = size + padding;
    char* aligned_ptr = &buffer[buffer_pos + padding];
    buffer_pos += total_size;
    return aligned_ptr;
}
void operator delete(void* ptr, unsigned long) {}
void operator delete(void* ptr) {}
void operator delete[](void* ptr) {}