#ifndef _SPAWNER_RUNNER_H_
#define _SPAWNER_RUNNER_H_

#include <string>
#include <map>// <-- for pipes only
#include <inc/platform.h>
#include <inc/pipes.h>
#include <inc/status.h>
#include <inc/report.h>
#include <inc/options.h>

class runner {
protected:
    unsigned long long creation_time;
    DWORD process_creation_flags;
    startupinfo_t si;
    bool running_async;
    options_class options;
    std::string program;
    std::string force_program;
    std::map<pipes_t, pipe_class*> pipes;
    process_info_t process_info;
    process_status_t process_status;
    bool running;
    report_class report;
    thread_t running_thread;
    handle_t init_semaphore;//rename to mutex_init_signal
    static handle_t main_job_object;
    static handle_t main_job_object_access_mutex;
    static bool allow_breakaway;
    void set_allow_breakaway(bool allow);
    bool init_process(char *cmd, const char *wd);
    bool init_process_with_logon(char *cmd, const char *wd);
    virtual void create_process();
    virtual void free();
    virtual void wait();
    virtual void debug();
    virtual void requisites();
    static thread_return_t async_body(thread_param_t param);
public:
    runner(const std::string &program, const options_class &options);
    virtual ~runner();
    unsigned long get_exit_code();
    virtual process_status_t get_process_status();
    exception_t get_exception();
    unsigned long get_id();
    std::string get_program() const;
    options_class get_options() const;
    virtual report_class get_report();
    virtual unsigned long long get_time_since_create();
    static unsigned long long get_current_time();
    virtual handle_t get_process_handle();
    virtual void get_times(unsigned long long *_creation_time, unsigned long long *exit_time, unsigned long long *kernel_time, unsigned long long *user_time);

    virtual void run_process();
    virtual void run_process_async();
    bool wait_for(const unsigned long &interval = INFINITE);
    bool wait_for_init(const unsigned long &interval);
    virtual void safe_release();
    void set_pipe(const pipes_t &pipe_type, pipe_class *pipe_object);
    pipe_class *get_pipe(const pipes_t &pipe_type);
};

#endif//_SPAWNER_RUNNER_H_
