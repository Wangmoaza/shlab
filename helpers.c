/* Here are helper routines that we've provided for you */

/* 
 * parseline - Parse the command line and build the argv array.
 * 
 * Characters enclosed in single quotes are treated as a single
 * argument.  Return true if the user has requested a BG job, false if
 * the user has requested a FG job.  
 */
int parseline(const char *cmdline, char **argv); 

/* clearjob - Clear the entries in a job struct */
void clearjob(struct job_t *job);

/* initjobs - Initialize the job list */
void initjobs(struct job_t *jobs);

/* maxjid - Returns largest allocated job ID */
int maxjid(struct job_t *jobs); 

/* addjob - Add a job to the job list */
int addjob(struct job_t *jobs, pid_t pid, int state, char *cmdline);

/* deletejob - Delete a job whose PID=pid from the job list */
int deletejob(struct job_t *jobs, pid_t pid); 

/* fgpid - Return PID of current foreground job, 0 if no such job */
pid_t fgpid(struct job_t *jobs);

/* getjobpid  - Find a job (by PID) on the job list */
struct job_t *getjobpid(struct job_t *jobs, pid_t pid);

/* getjobjid  - Find a job (by JID) on the job list */
struct job_t *getjobjid(struct job_t *jobs, int jid); 

/* pid2jid - Map process ID to job ID */
int pid2jid(pid_t pid); 

/* listjobs - Print the job list */
void listjobs(struct job_t *jobs);

/*
 * usage - print a help message
 */
void usage(void);

/*
 * unix_error - unix-style error routine
 */
void unix_error(char *msg);

/*
 * app_error - application-style error routine
 */
void app_error(char *msg);

/*
 * sigquit_handler - The driver program can gracefully terminate the
 *    child shell by sending it a SIGQUIT signal.
 */
void sigquit_handler(int sig);

/*
 * Signal - wrapper for the sigaction function
 */
handler_t *Signal(int signum, handler_t *handler);