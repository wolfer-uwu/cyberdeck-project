#include "quantum.h"
#include "pointing_device.h"
#include "timer.h"
#define BTN_PIN GP29
#define RIGHT_PIN GP28
#define LEFT_PIN GP27
#define DOWN_PIN GP17
#define UP_PIN GP26
#define WHITE_LED_PIN GP19
#define BOUNCE_INTERVAL 30
#define BASE_MOVE_PIXELS 5
#define EXPONENTIAL_BOUND 15
#define EXPONENTIAL_BASE 1.2

typedef struct {
    uint8_t pins[2];
    bool last_actions[2];
    uint32_t last_action_times[2];
} Direction;

Direction x_dir, y_dir;

void pointing_device_init(void) {
    setPinInputHigh(UP_PIN);
    setPinInputHigh(DOWN_PIN);
    setPinInputHigh(LEFT_PIN);
    setPinInputHigh(RIGHT_PIN);
    setPinInputHigh(BTN_PIN);
    setPinOutput(WHITE_LED_PIN);
    writePinHigh(WHITE_LED_PIN);

    x_dir = (Direction){{LEFT_PIN, RIGHT_PIN}, {false, false}, {0, 0}};
    y_dir = (Direction){{UP_PIN, DOWN_PIN}, {false, false}, {0, 0}};
}

int16_t read_action(Direction *dir) {
    for (int i = 0; i < 2; ++i) {
        bool current_action = !readPin(dir->pins[i]);
        uint32_t current_time = timer_read();

        if (current_action != dir->last_actions[i]) {
            dir->last_actions[i] = current_action;
            int32_t time_diff = current_time - dir->last_action_times[i];
            int32_t exponential = (EXPONENTIAL_BOUND - time_diff);
            exponential = (exponential > 0) ? exponential : 1;

            float move_multiply = EXPONENTIAL_BASE;
            for (int j = 0; j < exponential; ++j) {
                move_multiply *= EXPONENTIAL_BASE;
            }

            dir->last_action_times[i] = current_time;
            return (i == 0) ? (-1) * BASE_MOVE_PIXELS * move_multiply : BASE_MOVE_PIXELS * move_multiply;
        }
    }
    return 0;
}

report_mouse_t pointing_device_task_kb(report_mouse_t mouse_report) {
    int16_t x_move = read_action(&x_dir);
    int16_t y_move = read_action(&y_dir);

    mouse_report.x = x_move;
    mouse_report.y = y_move;

    static bool btn_state = false;
    static uint32_t btn_last_action_time = 0;
    bool btn_read_state = !readPin(BTN_PIN);

    if (btn_read_state != btn_state) {
        uint32_t btn_current_action_time = timer_read();
        if (btn_current_action_time - btn_last_action_time > BOUNCE_INTERVAL) {
            btn_state = btn_read_state;
            btn_last_action_time = btn_current_action_time;
            writePin(WHITE_LED_PIN, !btn_state);
            mouse_report.buttons = btn_state ? MOUSE_BTN1 : 0;
        }
    }

    return mouse_report;
}
