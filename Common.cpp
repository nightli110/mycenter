#include"Common.hpp"

using namespace std;

std::string JsonToString(const Json::Value& json) {
  Json::StreamWriterBuilder builder;
  return Json::writeString(builder, json);
}

Json::Value StringToJson(const std::string& str) {
  Json::Value json;

  Json::CharReaderBuilder builder;
  std::stringstream stream(str);
  std::string errs;
  if (!Json::parseFromStream(builder, stream, &json, &errs)) {
    std::cerr << errs << std::endl;
  }

  return json;
}

