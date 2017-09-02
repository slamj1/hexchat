typedef int... time_t;

typedef struct _hexchat_plugin hexchat_plugin;
typedef struct _hexchat_list hexchat_list;
typedef struct _hexchat_hook hexchat_hook;
typedef struct _hexchat_context hexchat_context;
typedef struct {
	time_t server_time_utc; /* 0 if not used */
} hexchat_event_attrs;

hexchat_hook *
hexchat_hook_command (hexchat_plugin *ph,
		    const char *name,
		    int pri,
		    int (*callback) (char *word[], char *word_eol[], void *user_data),
		    const char *help_text,
		    void *userdata);

hexchat_event_attrs *hexchat_event_attrs_create (hexchat_plugin *ph);

void hexchat_event_attrs_free (hexchat_plugin *ph, hexchat_event_attrs *attrs);

hexchat_hook *
hexchat_hook_server (hexchat_plugin *ph,
		   const char *name,
		   int pri,
		   int (*callback) (char *word[], char *word_eol[], void *user_data),
		   void *userdata);

hexchat_hook *
hexchat_hook_server_attrs (hexchat_plugin *ph,
		   const char *name,
		   int pri,
		   int (*callback) (char *word[], char *word_eol[],
							hexchat_event_attrs *attrs, void *user_data),
		   void *userdata);

hexchat_hook *
hexchat_hook_print (hexchat_plugin *ph,
		  const char *name,
		  int pri,
		  int (*callback) (char *word[], void *user_data),
		  void *userdata);

hexchat_hook *
hexchat_hook_print_attrs (hexchat_plugin *ph,
		  const char *name,
		  int pri,
		  int (*callback) (char *word[], hexchat_event_attrs *attrs,
						   void *user_data),
		  void *userdata);

hexchat_hook *
hexchat_hook_timer (hexchat_plugin *ph,
		  int timeout,
		  int (*callback) (void *user_data),
		  void *userdata);

hexchat_hook *
hexchat_hook_fd (hexchat_plugin *ph,
		int fd,
		int flags,
		int (*callback) (int fd, int flags, void *user_data),
		void *userdata);

void *
hexchat_unhook (hexchat_plugin *ph,
	      hexchat_hook *hook);

void
hexchat_print (hexchat_plugin *ph,
	     const char *text);

void
hexchat_command (hexchat_plugin *ph,
	       const char *command);

int
hexchat_nickcmp (hexchat_plugin *ph,
	       const char *s1,
	       const char *s2);

int
hexchat_set_context (hexchat_plugin *ph,
		   hexchat_context *ctx);

int
hexchat_emit_print (hexchat_plugin *ph,
		  const char *event_name, ...);

int
hexchat_emit_print_attrs (hexchat_plugin *ph, hexchat_event_attrs *attrs,
						  const char *event_name, ...);

hexchat_context *
hexchat_find_context (hexchat_plugin *ph,
		    const char *servname,
		    const char *channel);

hexchat_context *
hexchat_get_context (hexchat_plugin *ph);

const char *
hexchat_get_info (hexchat_plugin *ph,
		const char *id);

int
hexchat_get_prefs (hexchat_plugin *ph,
		 const char *name,
		 const char **string,
		 int *integer);

hexchat_list *
hexchat_list_get (hexchat_plugin *ph,
		const char *name);

void
hexchat_list_free (hexchat_plugin *ph,
		 hexchat_list *xlist);

const char * const *
hexchat_list_fields (hexchat_plugin *ph,
		   const char *name);

int
hexchat_list_next (hexchat_plugin *ph,
		 hexchat_list *xlist);

const char *
hexchat_list_str (hexchat_plugin *ph,
		hexchat_list *xlist,
		const char *name);

int
hexchat_list_int (hexchat_plugin *ph,
		hexchat_list *xlist,
		const char *name);

time_t
hexchat_list_time (hexchat_plugin *ph,
		 hexchat_list *xlist,
		 const char *name);

void *
hexchat_plugingui_add (hexchat_plugin *ph,
		     const char *filename,
		     const char *name,
		     const char *desc,
		     const char *version,
		     char *reserved);

void
hexchat_plugingui_remove (hexchat_plugin *ph,
			void *handle);

char *
hexchat_gettext (hexchat_plugin *ph,
	       const char *msgid);

void
hexchat_send_modes (hexchat_plugin *ph,
		  const char **targets,
		  int ntargets,
		  int modes_per_line,
		  char sign,
		  char mode);

char *
hexchat_strip (hexchat_plugin *ph,
	     const char *str,
	     int len,
	     int flags);

void
hexchat_free (hexchat_plugin *ph,
	    void *ptr);

int
hexchat_pluginpref_set_str (hexchat_plugin *ph,
		const char *var,
		const char *value);

int
hexchat_pluginpref_get_str (hexchat_plugin *ph,
		const char *var,
		char *dest);

int
hexchat_pluginpref_set_int (hexchat_plugin *ph,
		const char *var,
		int value);
int
hexchat_pluginpref_get_int (hexchat_plugin *ph,
		const char *var);

int
hexchat_pluginpref_delete (hexchat_plugin *ph,
		const char *var);

int
hexchat_pluginpref_list (hexchat_plugin *ph,
		char *dest);
