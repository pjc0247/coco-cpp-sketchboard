#include <coco.h>

#include <string>

class game_account : public coco::handler{
public:
  game_account(){
    route("create", &game_account::on_create);
    route("delete", &game_account::on_delete);
    route("info", &game_account::on_info);
  }
  
  std::string on_create(coco::request *request){
    return "";
  }
  std::string on_delete(coco::request *request){
    return "";
  }
  std::string on_info(coco::request *request){
    return "";
  }
};

int main(){
  coco::setup(
    "0.0.0.0", 8080);
  
  coco::route(
    "game/account", new game_account());
  coco::route(
    "game/notice", new game_notice());
    
  return coco::run();
}
