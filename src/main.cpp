#include <SPI.h>
#include <mcp2515.h>

struct can_frame canMsg;
MCP2515 mcp2515(10);

void setup()
{
    Serial.begin(115200);

    mcp2515.reset();
    mcp2515.setBitrate(CAN_500KBPS, MCP_8MHZ);
    mcp2515.setNormalMode();
}


void loop()
{
    if (mcp2515.readMessage(&canMsg) == MCP2515::ERROR_OK)
    {
        Serial.print("ID: ");
        Serial.print(canMsg.can_id, HEX);
        Serial.print(" DLC: ");
        Serial.print(canMsg.can_dlc, HEX);
        Serial.print(" Data: ");

        for (int i = 0; i < canMsg.can_dlc; i++)
        {
            Serial.print(canMsg.data[i], HEX);
            Serial.print(" ");
        }

        Serial.println();
    }
}
