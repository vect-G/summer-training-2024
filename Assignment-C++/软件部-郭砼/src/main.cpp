#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include <cpr/cpr.h> 

int main()
{
    std::ifstream config_file("config.json");
    if (!config_file.is_open())
    {
        std::cerr << "无法打开配置文件!" << std::endl;
        return 1;
    }

    nlohmann::json config;
    config_file >> config;

    std::string url = config["url"];
    std::cout << "读取的 URL: " << url << std::endl;

    cpr::Response r = cpr::Get(cpr::Url{url});

    std::ofstream outfile("output.html");
    outfile << r.text;
    outfile.close();

    std::cout << "网页内容已保存到 output.html" << std::endl;

    return 0;
}
