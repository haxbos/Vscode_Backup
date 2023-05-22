#include <iostream>
#include <hiredis/hiredis.h>

int main() {
    // 连接 Redis 服务器
    redisContext *c = redisConnect("159.138.143.137", 6379);
    if (c == nullptr || c->err) {
        std::cout << "Connection error: " << c->errstr << std::endl;
        return -1;
    }

    // 发送命令并获取响应
    redisReply *reply = reinterpret_cast<redisReply *>(redisCommand(c, "SET mykey \"Hello world\""));
    if (reply == nullptr) {
        std::cout << "Redis command error!" << std::endl;
        return -1;
    }

    // 处理响应数据
    std::cout << reply->str << std::endl;

    // 释放资源
    freeReplyObject(reply);
    redisFree(c);

    return 0;
}
