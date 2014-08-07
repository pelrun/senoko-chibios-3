/*
    ChibiOS/RT - Copyright (C) 2006-2013 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#include "ch.h"
#include "hal.h"
#include "shell.h"
#include "chprintf.h"
#include "senoko.h"

<<<<<<< HEAD
/* Global stream variable, lets modules use chprintf().*/
void *stream;

void cmd_threads(BaseSequentialStream *chp, int argc, char *argv[]);
void cmd_mem(BaseSequentialStream *chp, int argc, char *argv[]);
void cmd_gg(BaseSequentialStream *chp, int argc, char *argv[]);
void cmd_stats(BaseSequentialStream *chp, int argc, char *argv[]);
void cmd_chg(BaseSequentialStream *chp, int argc, char *argv[]);
void cmd_leds(BaseSequentialStream *chp, int argc, char *argv[]);
void cmd_reboot(BaseSequentialStream *chp, int argc, char *argv[]);

static const ShellCommand shellCommands[] = {
  {"chg", cmd_chg},
  {"gg", cmd_gg},
  {"leds", cmd_leds},
  {"mem", cmd_mem},
  {"stats", cmd_stats},
  {"reboot", cmd_reboot},
=======
void cmd_threads(BaseSequentialStream *chp, int argc, char *argv[]);
void cmd_mem(BaseSequentialStream *chp, int argc, char *argv[]);

static const ShellCommand shellCommands[] = {
  {"mem", cmd_mem},
>>>>>>> 4177a65a07b748bb28ca7f5533e1ca3dadba5e2c
  {"threads", cmd_threads},
  {NULL, NULL}
};

static const ShellConfig shellConfig = {
<<<<<<< HEAD
  stream_driver,
  shellCommands
};

static const SerialConfig serialConfig = {
  115200,
  0,
  0,
  0,
};

static thread_t *shell_tp = NULL;
static THD_WORKING_AREA(waShellThread, 2048);

void senokoShellInit(void) {
  sdStart(serialDriver, &serialConfig);
  stream = stream_driver;

  shellInit();
}

void senokoShellRestart(void) {
  /* Recovers memory of the previous shell. */
  if (shell_tp && chThdTerminatedX(shell_tp))
    chThdRelease(shell_tp);
  shell_tp = shellCreateStatic(&shellConfig, waShellThread,
=======
  stream,
  shellCommands
};

static thread_t *shellTp = NULL;
static THD_WORKING_AREA(waShellThread, 2048);

int shellTerminated(void)
{
  if (!shellTp)
    return TRUE;
  if (chThdTerminatedX(shellTp)) {
    /* Recovers memory of the previous shell. */
    chThdRelease(shellTp);
    return TRUE;
  }
  return FALSE;
}

void shellRestart(void)
{
  shellTp = shellCreateStatic(&shellConfig, waShellThread,
>>>>>>> 4177a65a07b748bb28ca7f5533e1ca3dadba5e2c
                              sizeof(waShellThread), NORMALPRIO);
}
