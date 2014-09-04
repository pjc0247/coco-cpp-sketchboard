#include <coco.h>

int main(){
  coco::db::initialize(
    "localhost",
    "db_name",
    "user", "password");
  
  /* start transaction */
  coco::db::begin(); 
  
  /* SELECT */
  auto *row = coco::db::from("accounts")
    ->where("id", "pjc0247")
    ->where("password", "asdf1234")
    ->find_one();
    
  if( row == nullptr )
    printf("cannot find \'pjc0247\'");
  else{
    printf(
      "id : %s\n"
      "nickname : %s\n"
      "level : %s\n",
      row->get("id"),
      row->get("nickname"),
      row->get("level"));
    
    /* UPDATE */  
    row->set("nickname", "foobar");
    row->save();
    
    delete row;
  }
  
  /* end transaction */
  coco::db::commit();
    
  return 0;
}
