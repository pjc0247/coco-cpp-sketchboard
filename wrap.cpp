#include <coco.h>

/* wrap
 *
 * high-level interface 제공
 * 이름 미정 
 */

class game_account : public coco::wrap::handler{
public:
  game_account(){
    route("create", &game_account::create);
  }
  
  void create(){
    int code = 0;
    int ret = validate(
      "id", "required va-length[8]",
      "password", "required va-length[8-32]",
      "nickname", "required va-length[8-32]",
      nullptr);
    
    if( ret == errno::invalid_param )
      code = 0;
      
    response(
      "result[int]", code,
      "uniq_id[string], "some_unique_id",
      nullptr);
  }
};
