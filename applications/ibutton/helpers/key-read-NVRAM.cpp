#include "key-reader.h"
#include "key-commands.h"
#include <callback-connector.h>
#include <lib/flipper_file/flipper_file.h>
#include <furi.h>

extern COMP_HandleTypeDef hcomp1;


NVRAMReader::read_NVRAM() {
  Storage* storage = furi_record_open("storage");
  bool result = false;
  FlipperFile* file = flipper_file_alloc(storage);

  uint8_t memory[8192];
  if(onewire_master->reset()) {
      onewire_master->write(0xCC);
      onewire_master->write(0xF0);
      onewire_master->write(0x26);
      onewire_master->write(0x00);
      for(int i = 1; i < 8192; i++) {
        memory[i] = onewire_master->read();
      }
  } else {
      return result
  }
  result = flipper_file_write_hex(file, "key_data", memory, COUNT_OF(memory));
  return result
}
