
/* -----THE SYSTEM CONTROL IOT DEVICES----*/
/*---------------Tran Minh Tri------------*/

/*-----DEFINE LIBRARIES AND VARIABLES----*/
#include <stdio.h>
#include <stdarg.h>

typedef enum {
    LIGHT,
    AIR_CONDITIONER,
    FINGERPRINT_LOCK,
    MUSIC_PLAYER
} DeviceType;

typedef enum {
    ON,
    OFF,
    SET_TEMPERATURE,
    SET_MODE,
    UNLOCK,
    LOCK,
    SET_VOLUME,
    CHANGE_TRACK,
    MODE_COOLER,
    MODE_FAN
} CommandType;


/* ---------DEFINE FUNCTION-------*/
void controlDevice(DeviceType device, ...) {
    va_list args;
    va_start(args, device);

    // Choose the device to control
    switch (device) {

        // Device is Light: ON, OFF
        case LIGHT: {
            CommandType cmd = va_arg(args, CommandType);
            switch (cmd)
            {
            case ON:
                printf("Light turned ON\n");
                break;
            case OFF:
                printf("Light turned OFF\n");
                break;
            default:
                printf("Command not found for the Light\n");
                break;
            }
        }
        break;

        // Device is Air conditioner: ON, OFF, SET_TEMPERATURE, SET_MODE
        case AIR_CONDITIONER: {
            CommandType cmd = va_arg(args, CommandType);
            switch (cmd)
            {
            case ON:
                printf("Air Conditioner turned ON\n");
                break;
            case OFF:
                printf("Air Conditioner turned OFF\n");
                break;
            case SET_TEMPERATURE: {
                int temp = va_arg(args, int);
                printf("Air Conditioner temperature set to %d degrees\n", temp);
            }
            break;
            case SET_MODE: {
                int mode = va_arg(args, int);
                switch (mode)
                {
                case MODE_COOLER:
                    printf("Air Conditioner set to cooler mode \n");
                    break;
                case MODE_FAN:
                    printf("Air Conditioner set to fan mode \n");
                    break;
                default:
                    printf("Command not found for mode of the Air Conditioner\n");
                    break;
                }
            break;
            }
            default:
            printf("Command not found for Air Conditioner\n");
            break;
            }
        }
        break;

        // Device is Fringer Lock: ON, OFF
        case FINGERPRINT_LOCK: {
            CommandType cmd = va_arg(args, CommandType);
            switch (cmd)
            {
            case ON:
                printf("Fringerprint Lock is Loked\n");
                break;
            case OFF:
                printf("Fringerprint Lock is Unlocked\n");
                break;
            default:
                printf("Command not found for the Fingerprint Lock\n");
                break;
            }
            break;
        }
        break;

        // Device is Music Player: ON, OFF, SET_VOLUME, CHANGE_TRACK
        case MUSIC_PLAYER: {
            CommandType cmd = va_arg(args, CommandType);
            switch (cmd)
            {
            case ON:
                printf("Music Player turned ON\n");
                break;
            case OFF:
                printf("Music Player turned OFF\n");
                break;
            case SET_VOLUME: {
                int volume = va_arg(args, int);
                printf("The volume set to %d\n", volume);
                break;
            }
            case CHANGE_TRACK:
                printf("Music Player changed track\n");
                break;
            default:
                printf("Command not found for Music Player\n");
                break;
            }
            break;
        }
    default:
        printf("Command not found for Control Device\n");
    }

    va_end(args);
}


/* ---------MAIN PROGRAM--------*/
int main() {
    controlDevice(LIGHT, ON);

    controlDevice(AIR_CONDITIONER, ON);
    controlDevice(AIR_CONDITIONER, SET_TEMPERATURE, 24);
    controlDevice(AIR_CONDITIONER, SET_MODE, MODE_COOLER);

    controlDevice(FINGERPRINT_LOCK, ON);

    controlDevice(MUSIC_PLAYER, ON);
    controlDevice(MUSIC_PLAYER, SET_VOLUME, 50);
    controlDevice(MUSIC_PLAYER, CHANGE_TRACK);

    return 0;
}


