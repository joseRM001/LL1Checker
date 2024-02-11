#include <fstream>
#include <iterator>
#include <vector>
class lexer {
    std::string filename_;
    std::vector<std::string> tokens_;
    unsigned current_;
    public:
    lexer(const std::string &filename);
    std::string next();
  private:
    void tokenize();
    void make_lexer();
    void compile();
    const std::string LEXER_FILENAME {"lexer.l"};
    const std::string SRC_PATH {"./src"};
    const std::string LIB_PATH {"./lib"};
};
