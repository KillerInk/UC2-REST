#include "State.h"



// Custom function accessible by the API
void State::act() {
  // here you can do something
  if (DEBUG) Serial.println("state_act_fct");

  // assign default values to thhe variables
  if (jsonDocument->containsKey("restart")) {
    ESP.restart();
  }
  // assign default values to thhe variables
  if (jsonDocument->containsKey("delay")) {
    int mdelayms = (*jsonDocument)["delay"];
    delay(mdelayms);
  }
  if (jsonDocument->containsKey("isBusy")) {
    isBusy = (*jsonDocument)["isBusy"];
  }

  if (jsonDocument->containsKey("pscontroller")) {
    #if defined IS_PS3 || defined IS_PS4
      gp_controller.IS_PSCONTROLER_ACTIVE = (*jsonDocument)["pscontroller"];
    #endif
  }
  jsonDocument->clear();
  (*jsonDocument)["return"] = 1;
}

void State::set() {
  // here you can set parameters

  int isdebug = (*jsonDocument)["isdebug"];
  DEBUG = isdebug;
  jsonDocument->clear();
  (*jsonDocument)["return"] = 1;

}

// Custom function accessible by the API
void State::get() {
  // GET SOME PARAMETERS HERE
  if (jsonDocument->containsKey("isBusy")) {
    jsonDocument->clear();
    (*jsonDocument)["isBusy"] = isBusy; // returns state of function that takes longer to finalize (e.g. motor)
  }

  else if (jsonDocument->containsKey("pscontroller")) {
    jsonDocument->clear();
    #if defined IS_PS3 || defined IS_PS4
    jsonDocument["pscontroller"] = gp_controller.IS_PSCONTROLER_ACTIVE; // returns state of function that takes longer to finalize (e.g. motor)
    #endif
  }
  else {
    jsonDocument->clear();
    (*jsonDocument)["identifier_name"] = identifier_name;
    (*jsonDocument)["identifier_id"] = identifier_id;
    (*jsonDocument)["identifier_date"] = identifier_date;
    (*jsonDocument)["identifier_author"] = identifier_author;
    (*jsonDocument)["identifier_setup"] = pins->identifier_setup;
  }
}

void State::printInfo() {
  if (DEBUG) Serial.println("You can use this software by sending JSON strings, A full documentation can be found here:");
  if (DEBUG) Serial.println("https://github.com/openUC2/UC2-REST/");
  //Serial.println("A first try can be: \{\"task\": \"/state_get\"");
}

char *State::bda2str(const uint8_t* bda, char *str, size_t size)
{
  if (bda == NULL || str == NULL || size < 18) {
    return NULL;
  }
  sprintf(str, "%02x:%02x:%02x:%02x:%02x:%02x",
          bda[0], bda[1], bda[2], bda[3], bda[4], bda[5]);
  return str;
}
void State::clearBlueetoothDevice() {
  Serial.print("ESP32 bluetooth address: "); Serial.println(bda2str(esp_bt_dev_get_address(), bda_str, 18));
  // Get the numbers of bonded/paired devices in the BT module
  int count = esp_bt_gap_get_bond_device_num();
  if (!count) {
    Serial.println("No bonded device found.");
  } else {
    Serial.print("Bonded device count: "); Serial.println(count);
    if (PAIR_MAX_DEVICES < count) {
      count = PAIR_MAX_DEVICES;
      Serial.print("Reset bonded device count: "); Serial.println(count);
    }
    esp_err_t tError =  esp_bt_gap_get_bond_device_list(&count, pairedDeviceBtAddr);
    if (ESP_OK == tError) {
      for (int i = 0; i < count; i++) {
        Serial.print("Found bonded device # "); Serial.print(i); Serial.print(" -> ");
        Serial.println(bda2str(pairedDeviceBtAddr[i], bda_str, 18));
        if (REMOVE_BONDED_DEVICES) {
          esp_err_t tError = esp_bt_gap_remove_bond_device(pairedDeviceBtAddr[i]);
          if (ESP_OK == tError) {
            Serial.print("Removed bonded device # ");
          } else {
            Serial.print("Failed to remove bonded device # ");
          }
          Serial.println(i);
        }
      }
    }
  }
}