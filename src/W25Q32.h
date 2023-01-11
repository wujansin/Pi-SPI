//#include <arduino.h>
//#include <SPI.h>

//  W25Q32 使用開始
void W25Q32_begin(uint8_t cs);
// 取得狀態佔存器1的值
uint8_t W25Q32_readStatusReg1(void);
// 取得狀態佔存器2的值
uint8_t W25Q32_readStatusReg2();
// JEDEC ID(Manufacture, Memory Type,Capacity) 取得
void W25Q32_readManufacturer(uint8_t* d);
// Unique ID 取得
void W25Q32_readUniqieID(uint8_t* d);
//在寫入等處理中檢查
bool W25Q32_IsBusy(void);
// Power Down指定 
void W25Q32_powerDown(void);
// 寫入致能
void W25Q32_WriteEnable(void);
// 寫入禁能
void W25Q32_WriteDisable(void);
// 讀取數據
uint16_t W25Q32_read(uint32_t addr,uint8_t *buf,uint16_t n);
// 高速讀取數據
uint16_t W25Q32_fastread(uint32_t addr,uint8_t *buf,uint16_t n);
// 扇區單位資料消除
bool  W25Q32_eraseSector(uint16_t sect_no, bool flgwait);
// 64KB塊單位消除
bool  W25Q32_erase64Block(uint16_t blk_no, bool flgwait);
// 32KB塊單位消除
bool  W25Q32_erase32Block(uint16_t blk_no, bool flgwait);
// 全部資料消除
bool  W25Q32_eraseAll(bool flgwait);
// 寫入資料
uint16_t W25Q32_pageWrite(uint16_t sect_no, uint16_t inaddr, uint8_t* data, uint16_t n);