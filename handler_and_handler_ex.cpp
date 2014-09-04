#include <coco.h>

/* 불필요한 데이터의 복사를 방지하기 위해
 * request와 request_ex구조체를 분리
 * request_ex는 request보다 많은 정보를 담고 있음,
 * 
 * coco::handler를 상속받으면 request
 * coco::handler_ex를 상속받으면 request_ex
 */


class test : public coco::handler{
public:
  test(){
    route("hello", &test::hello);
  }
  
  coco::http::response hello(
    coco::http::request *request){
    
    coco::http::response response;
    
    response.content = "hello world";
    response.header["content-type"] = "text/plain";
    
    return response;
  }
};

class test_ex : public coco::handler_ex{
public:
  test_ex(){
    route("hello", &test::hello);
  }
  
  coco::http::response hello(
    coco::http::request_ex *request){
    /* request_ex 구조체에서는 아래의 데이터를 추가로 담고 있다.
     * 
     * length : 입력받은 request의 총 길이
     * header : 헤더 정보 (kvpair)
     */
    
    coco::http::response response;
    
    return response;
  }
};
