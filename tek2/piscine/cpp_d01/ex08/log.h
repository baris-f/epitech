#ifndef LOG_H_
# define LOG_H_

enum	LogLevel
  {
    Error,
    Warning,
    Notice,
    Info,
    Debug
  };

enum    LogLevel        get_log_level(void);
enum    LogLevel        set_log_level(enum LogLevel level);
int     set_log_file(char const* name);
int     close_log_file(void);
int     log_to_stdout(void);
int     log_to_stderr(void);
void    log_msg(enum LogLevel curlvl, char const *fmt, ...);
#endif /* !LOG_H_ */
