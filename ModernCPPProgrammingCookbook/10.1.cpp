#include <memory>
#include <string_view>
#include <map>
#include <functional>

class Image {};
class Bitmap : public Image {};
class PngImage : public Image{};
class JpgImage : public Image{};

struct IImageFactory {
    virtual std::unique_ptr<Image> Create(std::string_view type) = 0;
};

struct ImageFactory : public IImageFactory {
    std::unique_ptr<Image> Create(std::string_view type) override {
        if (type == "bitmap") {
            return std::make_unique<Bitmap>();
        } else if (type == "png") {
            return std::make_unique<PngImage>();
        } else if (type == "jpg") {
            return std::make_unique<JpgImage>();
        }
    }
    static std::map<std::string, std::function<std::unique_ptr<Image>()>> mapping;
};

std::map<std::string, std::function<std::unique_ptr<Image>()>> ImageFactory::mapping {
    {"bitmap", []() { return std::make_unique<Bitmap>(); }},
    {"png", []() { return std::make_unique<PngImage>(); }},
    {"jpg", []() { return std::make_unique<JpgImage>(); }},
};

struct IImageFactoryByType {
    virtual std::unique_ptr<Image> Create(std::type_info const& type) = 0;
};

struct ImageFactoryByType : public IImageFactoryByType {
    std::unique_ptr<Image> Create(std::type_info const& type) override {
        auto it = mapping.find(&type);
        if (it == mapping.end()) {
            return it->second;
        }
        return nullptr;
    }
  private:
    static std::map<std::type_info const*, std::function<std::unique_ptr<Image>()>> mapping;    
};

std::map<std::type_info const*, std::function<std::unique_ptr<Image>()>> ImageFactoryByType::mapping {
    {&typeid(Bitmap), []() { return std::make_unique<Bitmap>(); }},
    {&typeid(PngImage), []() { return std::make_unique<PngImage>(); }},
    {&typeid(JpgImage), []() { return std::make_unique<JpgImage>(); }},
};


int main() {
    auto factory = std::make_unique<ImageFactory>();
    auto image = factory->Create("bitmap");

    auto typeFactory = std::make_unique<ImageFactoryByType>();
    auto image = typeFactory->Create(typeid(Bitmap));
    return 0;
}