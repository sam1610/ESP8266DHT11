



void DHTstart(){
  dht.begin();
}

float ReadT(){
  float t = dht.readTemperature();
  return t;
}

float ReadH(){
  float h = dht.readHumidity();
  return h;
}