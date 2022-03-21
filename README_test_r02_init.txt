The following is expected test output (mostly errors) for the initial 
release of the project before any of the functions specified in README01.txt
or README02.txt have been implemented. 

Note:
    1. some error messages will differ on different machines
    2. some tests pass because the initial implementation trivially passes
       a test, for example when NULL is the expected return value from a 
       a function under test. 
    3. the test output for the following files:
            ipc_jobqueue.c, job.c, joblog.c, jobqueue.c, mutex_peterson.c, 
            sem_jobqueue.c, shobject_name
       is when they are in their initial state before any of the functions 
       for the assignment have been implemented.

------------------------------------------------------
Running bin/test/test_ipc ...
Running test suite with seed 0xe52eb9ba...
/test_ipc/test_ipc                   [ ERROR ]
Error: test/test_ipc.c:67: assertion failed: ipc != ((void *)0) (0x0 != 0x0)
Error: test/test_ipc.c:102: assertion failed: ipc != ((void *)0) (0x0 != 0x0)
Error: child killed by signal 6
/test_ipc/test_ipc_err               [ OK    ] [ 0.00001200 / 0.00001100 CPU ]
1 of 2 (50%) tests successful, 0 (0%) test skipped.
------------------------------------------------------
------------------------------------------------------
Running bin/test/test_ipc_jobqueue ...
Running test suite with seed 0x7b498fa5...
/test_ipc_jobqueue/test_ipc_jobqueue_capacity[ ERROR ]
Error: child killed by signal 11
/test_ipc_jobqueue/test_ipc_jobqueue_capacity_null[ ERROR ]
Error: child killed by signal 11
/test_ipc_jobqueue/test_ipc_jobqueue_dequeue_fullq[ ERROR ]
Error: child killed by signal 11
/test_ipc_jobqueue/test_ipc_jobqueue_dequeue_inout[ ERROR ]
Error: child killed by signal 11
/test_ipc_jobqueue/test_ipc_jobqueue_dequeue_emptyq[ ERROR ]
Error: child killed by signal 11
/test_ipc_jobqueue/test_ipc_jobqueue_dequeue_heap[ ERROR ]
Error: child killed by signal 11
/test_ipc_jobqueue/test_ipc_jobqueue_dequeue_null[ ERROR ]
Error: child killed by signal 11
/test_ipc_jobqueue/test_ipc_jobqueue_enqueue_tofull[ ERROR ]
Error: child killed by signal 11
/test_ipc_jobqueue/test_ipc_jobqueue_enqueue_inout[ ERROR ]
Error: child killed by signal 11
/test_ipc_jobqueue/test_ipc_jobqueue_enqueue_fullq[ ERROR ]
Error: child killed by signal 11
/test_ipc_jobqueue/test_ipc_jobqueue_enqueue_null[ ERROR ]
Error: child killed by signal 11
/test_ipc_jobqueue/test_ipc_jobqueue_is_empty[ ERROR ]
Error: child killed by signal 11
/test_ipc_jobqueue/test_ipc_jobqueue_is_empty_notempty[ ERROR ]
Error: child killed by signal 11
/test_ipc_jobqueue/test_ipc_jobqueue_is_empty_null[ ERROR ]
Error: child killed by signal 11
/test_ipc_jobqueue/test_ipc_jobqueue_is_full_empty[ ERROR ]
Error: child killed by signal 11
/test_ipc_jobqueue/test_ipc_jobqueue_is_full_filling[ ERROR ]
Error: child killed by signal 11
/test_ipc_jobqueue/test_ipc_jobqueue_is_full_null[ ERROR ]
Error: child killed by signal 11
/test_ipc_jobqueue/test_ipc_jobqueue_peekhead_empty[ ERROR ]
Error: child killed by signal 11
/test_ipc_jobqueue/test_ipc_jobqueue_peekhead_full[ ERROR ]
Error: child killed by signal 11
/test_ipc_jobqueue/test_ipc_jobqueue_peekhead_heap[ ERROR ]
Error: child killed by signal 11
/test_ipc_jobqueue/test_ipc_jobqueue_peekhead_null[ ERROR ]
Error: child killed by signal 11
/test_ipc_jobqueue/test_ipc_jobqueue_peektail_empty[ ERROR ]
Error: child killed by signal 11
/test_ipc_jobqueue/test_ipc_jobqueue_peektail_full[ ERROR ]
Error: child killed by signal 11
/test_ipc_jobqueue/test_ipc_jobqueue_peektail_heap[ ERROR ]
Error: child killed by signal 11
/test_ipc_jobqueue/test_ipc_jobqueue_peektail_wrap[ ERROR ]
Error: child killed by signal 11
/test_ipc_jobqueue/test_ipc_jobqueue_peektail_null[ ERROR ]
Error: child killed by signal 11
0 of 26 (0%) tests successful, 0 (0%) test skipped.
------------------------------------------------------
------------------------------------------------------
Running bin/test/test_job ...
Running test suite with seed 0x7b88edc2...
/test_job/test_job_new               [ ERROR ]
Info: test/test_job.c:126: line 127: assert_valid_job call with i: 0
Error: test/test_job.c:106: assertion failed: job->pid == expected_pid (0 == 10003)
Error: child killed by signal 6
/test_job/test_job_new_null          [ ERROR ]
Info: test/test_job.c:141: line 142: assert_valid_job call
Error: test/test_job.c:106: assertion failed: job->pid == expected_pid (0 == 10004)
Error: child killed by signal 6
/test_job/test_job_copy_stack        [ ERROR ]
Error: test/test_job.c:159: assertion failed: cpy == &dst (0x16d7e3300 == 0x16d7e32d8)
Error: child killed by signal 6
/test_job/test_job_copy_heap         [ ERROR ]
Error: test/test_job.c:182: assertion failed: cpy != &src (0x16d7e3310 != 0x16d7e3310)
Error: child killed by signal 6
/test_job/test_job_copy_identity     [ ERROR ]
Info: test/test_job.c:205: line 206: assert_valid_job call with i: 0
Info: test/test_job.c:205: line 206: assert_valid_job call with i: 1
Info: test/test_job.c:205: line 206: assert_valid_job call with i: 2
Info: test/test_job.c:205: line 206: assert_valid_job call with i: 3
Info: test/test_job.c:205: line 206: assert_valid_job call with i: 4
Info: test/test_job.c:205: line 206: assert_valid_job call with i: 5
Info: test/test_job.c:205: line 206: assert_valid_job call with i: 6
Info: test/test_job.c:205: line 206: assert_valid_job call with i: 7
Info: test/test_job.c:205: line 206: assert_valid_job call with i: 8
Info: test/test_job.c:205: line 206: assert_valid_job call with i: 9
Info: test/test_job.c:205: line 206: assert_valid_job call with i: 10
Info: test/test_job.c:205: line 206: assert_valid_job call with i: 11
Info: test/test_job.c:205: line 206: assert_valid_job call with i: 12
Info: test/test_job.c:205: line 206: assert_valid_job call with i: 13
Info: test/test_job.c:205: line 206: assert_valid_job call with i: 14
Info: test/test_job.c:205: line 206: assert_valid_job call with i: 15
Error: test/test_job.c:220: assertion failed: cpy == &eq2src (0x16d7e3300 == 0x16d7e32d8)
Error: child killed by signal 6
/test_job/test_job_copy_null         [ OK    ] [ 0.00000300 / 0.00000400 CPU ]
/test_job/test_job_init_stack        [ ERROR ]
Info: test/test_job.c:251: line 251: assert_init_job call
Error: test/test_job.c:76: assertion failed: job->label[i] == '\0' ('\x58' == '\x00')
Error: child killed by signal 6
/test_job/test_job_init_heap         [ ERROR ]
Info: test/test_job.c:273: line 273: assert_init_job call
Info: test/test_job.c:284: line 285: assert_init_job call with i: 0
Error: test/test_job.c:76: assertion failed: job->label[i] == '\0' ('\x2a' == '\x00')
Error: child killed by signal 6
/test_job/test_job_init_null         [ ERROR ]
Error: child killed by signal 11
/test_job/test_job_is_equal          [ ERROR ]
Info: test/test_job.c:309: line 310: assert_job_equalities call with i: 0
Error: test/test_job.c:98: assertion failed: job_is_equal(j1, j2) is not false
Error: child killed by signal 6
/test_job/test_job_is_equal_init     [ ERROR ]
Info: test/test_job.c:330: line 331: assert_init_job call with i: 0
Error: test/test_job.c:337: assertion failed: job_is_equal(&j1, &j2) is not false
Error: child killed by signal 6
/test_job/test_job_is_equal_null     [ ERROR ]
Error: child killed by signal 11
/test_job/test_job_set_stack         [ ERROR ]
Info: test/test_job.c:376: line 377: assert_valid_job call with i: 0
Error: test/test_job.c:106: assertion failed: job->pid == expected_pid (1836987200 == 10015)
Error: child killed by signal 6
/test_job/test_job_set_heap          [ ERROR ]
Info: test/test_job.c:392: line 393: assert_valid_job call with i: 0
Error: test/test_job.c:106: assertion failed: job->pid == expected_pid (0 == 10016)
Error: child killed by signal 6
/test_job/test_job_set_null          [ ERROR ]
Info: test/test_job.c:411: line 412: assert_valid_job call
Error: test/test_job.c:106: assertion failed: job->pid == expected_pid (1836987200 == 10017)
Error: child killed by signal 6
1 of 15 (7%) tests successful, 0 (0%) test skipped.
------------------------------------------------------
------------------------------------------------------
Running bin/test/test_joblog ...
Running test suite with seed 0xd4a981f1...
/test_joblog/test_joblog_write_entry_cpid0[ FAIL  ]
/test_joblog/test_joblog_write_entry_cpid1[ FAIL  ]
/test_joblog/test_joblog_write_entry_cpid2[ FAIL  ]
/test_joblog/test_joblog_write_entry_cpid3[ FAIL  ]
/test_joblog/test_joblog_write_entry_errno[ OK    ] [ 0.00000400 / 0.00000400 CPU ]
/test_joblog/test_joblog_write_entry_null[ OK    ] [ 0.00000100 / 0.00000200 CPU ]
/test_joblog/test_joblog_read_entry_cpid0[ ERROR ]
Error: test/test_joblog.c:133: assertion failed: i == 11 (0 == 11)
Error: child killed by signal 6
/test_joblog/test_joblog_read_entry_cpid1[ ERROR ]
Error: test/test_joblog.c:133: assertion failed: i == 11 (0 == 11)
Error: child killed by signal 6
/test_joblog/test_joblog_read_entry_cpid2[ ERROR ]
Error: test/test_joblog.c:133: assertion failed: i == 11 (0 == 11)
Error: child killed by signal 6
/test_joblog/test_joblog_read_entry_cpid3[ ERROR ]
Error: test/test_joblog.c:133: assertion failed: i == 11 (0 == 11)
Error: child killed by signal 6
/test_joblog/test_joblog_read_entry_stack[ ERROR ]
Error: test/test_joblog.c:133: assertion failed: i == 11 (0 == 11)
Error: child killed by signal 6
/test_joblog/test_joblog_read_entry_rand[ ERROR ]
Error: test/test_joblog.c:157: assertion failed: rentry != ((void *)0) (0x0 != 0x0)
Error: child killed by signal 6
/test_joblog/test_joblog_read_entry_bounds[ OK    ] [ 0.00014600 / 0.00014600 CPU ]
/test_joblog/test_joblog_read_entry_null[ OK    ] [ 0.00000200 / 0.00000200 CPU ]
/test_joblog/test_joblog_read_entry_errno[ ERROR ]
Error: test/test_joblog.c:133: assertion failed: i == 11 (0 == 11)
Error: child killed by signal 6
/test_joblog/test_joblog_delete      [ ERROR ]
Error: test/test_joblog.c:405: assertion failed: access(log_fname[i], 0) == -1 (0 == -1)
Error: child killed by signal 6
4 of 16 (25%) tests successful, 0 (0%) test skipped.
------------------------------------------------------
------------------------------------------------------
Running bin/test/test_jobqueue ...
Running test suite with seed 0xbccec2a7...
/test_jobqueue/test_jobqueue_new     [ ERROR ]
Error: test/test_jobqueue.c:48: assertion failed: q != ((void*)0) (0x0 != 0x0)
Error: child killed by signal 6
/test_jobqueue/test_jobqueue_capacity[ ERROR ]
Error: test/test_jobqueue_common.c:176: assertion failed: test_jq->capacity(test_jq->q) == *test_jq->buf_size - 1 (0 == 127)
Error: child killed by signal 6
/test_jobqueue/test_jobqueue_capacity_null[ OK    ] [ 0.00000200 / 0.00000300 CPU ]
/test_jobqueue/test_jobqueue_dequeue_fullq[ ERROR ]
Error: test/test_jobqueue_common.c:203: assertion failed: is_init_job(&test_jq->jobs[prev_head]) is not true
Error: child killed by signal 6
/test_jobqueue/test_jobqueue_dequeue_inout[ ERROR ]
Error: test/test_jobqueue_common.c:235: assertion failed: is_init_job(&test_jq->jobs[prev_head]) is not true
Error: child killed by signal 6
/test_jobqueue/test_jobqueue_dequeue_emptyq[ OK    ] [ 0.00001300 / 0.00001400 CPU ]
/test_jobqueue/test_jobqueue_dequeue_heap[ ERROR ]
Error: test/test_jobqueue_common.c:301: assertion failed: is_init_job(hj) is not true
Error: child killed by signal 6
/test_jobqueue/test_jobqueue_dequeue_null[ OK    ] [ 0.00000100 / 0.00000000 CPU ]
/test_jobqueue/test_jobqueue_enqueue_tofull[ ERROR ]
Error: test/test_jobqueue_common.c:340: assertion failed: is_init_job(tail_j) is not false
Error: child killed by signal 6
/test_jobqueue/test_jobqueue_enqueue_inout[ ERROR ]
Error: test/test_jobqueue_common.c:403: assertion failed: is_init_job(tail_j) is not false
Error: child killed by signal 6
/test_jobqueue/test_jobqueue_enqueue_fullq[ ERROR ]
Error: test/test_jobqueue_common.c:453: assertion failed: tail == *test_jq->tail (127 == 41)
Error: child killed by signal 6
/test_jobqueue/test_jobqueue_enqueue_null[ ERROR ]
Error: child killed by signal 11
/test_jobqueue/test_jobqueue_is_empty[ OK    ] [ 0.00000400 / 0.00000400 CPU ]
/test_jobqueue/test_jobqueue_is_empty_notempty[ OK    ] [ 0.00001000 / 0.00000900 CPU ]
/test_jobqueue/test_jobqueue_is_empty_null[ OK    ] [ 0.00000400 / 0.00000300 CPU ]
/test_jobqueue/test_jobqueue_is_full_empty[ OK    ] [ 0.00000100 / 0.00000100 CPU ]
/test_jobqueue/test_jobqueue_is_full_filling[ ERROR ]
Error: test/test_jobqueue_common.c:530: assertion failed: test_jq->is_full(test_jq->q) is not true
Error: child killed by signal 6
/test_jobqueue/test_jobqueue_is_full_null[ ERROR ]
Error: test/test_jobqueue_common.c:537: assertion failed: test_jq->is_full(((void*)0)) is not true
Error: child killed by signal 6
/test_jobqueue/test_jobqueue_peekhead_empty[ OK    ] [ 0.00000300 / 0.00000300 CPU ]
/test_jobqueue/test_jobqueue_peekhead_full[ ERROR ]
Error: test/test_jobqueue_common.c:568: assertion failed: equal_jobs(h1ptr, &expected_j) is not true
Error: child killed by signal 6
/test_jobqueue/test_jobqueue_peekhead_heap[ ERROR ]
Error: test/test_jobqueue_common.c:630: assertion failed: ph != hj (0x13e00960c != 0x13e00960c)
Error: child killed by signal 6
/test_jobqueue/test_jobqueue_peekhead_null[ OK    ] [ 0.00000100 / 0.00000000 CPU ]
/test_jobqueue/test_jobqueue_peektail_empty[ OK    ] [ 0.00000100 / 0.00000100 CPU ]
/test_jobqueue/test_jobqueue_peektail_full[ ERROR ]
Error: child killed by signal 11
/test_jobqueue/test_jobqueue_peektail_heap[ ERROR ]
Error: child killed by signal 11
/test_jobqueue/test_jobqueue_peektail_wrap[ ERROR ]
Error: child killed by signal 11
/test_jobqueue/test_jobqueue_peektail_null[ OK    ] [ 0.00000100 / 0.00000100 CPU ]
/test_jobqueue/test_jobqueue_delete  [ OK    ] [ 0.00000100 / 0.00000100 CPU ]
12 of 28 (43%) tests successful, 0 (0%) test skipped.
------------------------------------------------------
------------------------------------------------------
Running bin/test/test_mutex_lockvar ...
Running test suite with seed 0x8bacee5a...
/test_mutex_lockvar/test_mutex_new   [ ERROR ]
Error: child killed by signal 11
/test_mutex_lockvar/test_mutex_new_null[ OK    ] [ 0.00000700 / 0.00000700 CPU ]
/test_mutex_lockvar/test_mutex_enter [ ERROR ]
Error: child killed by signal 11
/test_mutex_lockvar/test_mutex_enter_null[ OK    ] [ 0.00000500 / 0.00000500 CPU ]
/test_mutex_lockvar/test_mutex_leave [ OK    ] [ 0.00000400 / 0.00000400 CPU ]
/test_mutex_lockvar/test_mutex_leave_null[ OK    ] [ 0.00000200 / 0.00000200 CPU ]
4 of 6 (67%) tests successful, 0 (0%) test skipped.
------------------------------------------------------
------------------------------------------------------
Running bin/test/test_mutex_noop ...
Running test suite with seed 0x2503b47d...
/test_mutex_noop/test_mutex_new      [ OK    ] [ 0.00001100 / 0.00001100 CPU ]
/test_mutex_noop/test_mutex_new_null [ OK    ] [ 0.00000300 / 0.00000300 CPU ]
/test_mutex_noop/test_mutex_enter    [ OK    ] [ 0.00000500 / 0.00000400 CPU ]
/test_mutex_noop/test_mutex_enter_null[ OK    ] [ 0.00000100 / 0.00000200 CPU ]
/test_mutex_noop/test_mutex_leave    [ OK    ] [ 0.00000200 / 0.00000100 CPU ]
/test_mutex_noop/test_mutex_leave_null[ OK    ] [ 0.00000100 / 0.00000100 CPU ]
6 of 6 (100%) tests successful, 0 (0%) test skipped.
------------------------------------------------------
------------------------------------------------------
Running bin/test/test_mutex_peterson ...
Running test suite with seed 0xc5fbb221...
/test_mutex_peterson/test_mutex_new  [ ERROR ]
Error: test/test_mutex_peterson.c:33: assertion failed: m != ((void *)0) (0x0 != 0x0)
Error: child killed by signal 6
/test_mutex_peterson/test_mutex_new_null[ ERROR ]
Error: test/test_mutex_peterson.c:122: assertion failed: (*__error()) == 22 (0 == 22)
Error: child killed by signal 6
/test_mutex_peterson/test_mutex_enter_01[ ERROR ]
Error: child killed by signal 11
/test_mutex_peterson/test_mutex_enter_02[ ERROR ]
Error: child killed by signal 11
/test_mutex_peterson/test_mutex_enter_null[ OK    ] [ 0.00000700 / 0.00000600 CPU ]
/test_mutex_peterson/test_mutex_leave_01[ ERROR ]
Error: child killed by signal 11
/test_mutex_peterson/test_mutex_leave_02[ ERROR ]
Error: child killed by signal 11
/test_mutex_peterson/test_mutex_leave_null[ OK    ] [ 0.00000700 / 0.00000600 CPU ]
2 of 8 (25%) tests successful, 0 (0%) test skipped.
------------------------------------------------------
------------------------------------------------------
Running bin/test/test_proc ...
Running test suite with seed 0x6c5b2205...
/test_util/test_proc_new             [ OK    ] [ 0.00001900 / 0.00001800 CPU ]
/test_util/test_proc_new_null        [ OK    ] [ 0.00000500 / 0.00000600 CPU ]
2 of 2 (100%) tests successful, 0 (0%) test skipped.
------------------------------------------------------
------------------------------------------------------
Running bin/test/test_sem_jobqueue ...
Running test suite with seed 0x20c99f18...
/test_sem_jobqueue/test_sem_jobqueue_capacity[ ERROR ]
Error: child killed by signal 11
/test_sem_jobqueue/test_sem_jobqueue_capacity_null[ ERROR ]
Error: child killed by signal 11
/test_sem_jobqueue/test_sem_jobqueue_dequeue_null[ ERROR ]
Error: child killed by signal 11
/test_sem_jobqueue/test_sem_jobqueue_enqueue_null[ ERROR ]
Error: child killed by signal 11
/test_sem_jobqueue/test_sem_jobqueue_is_empty_null[ ERROR ]
Error: child killed by signal 11
/test_sem_jobqueue/test_sem_jobqueue_is_full_null[ ERROR ]
Error: child killed by signal 11
/test_sem_jobqueue/test_sem_jobqueue_peekhead_null[ ERROR ]
Error: child killed by signal 11
/test_sem_jobqueue/test_sem_jobqueue_peektail_null[ ERROR ]
Error: child killed by signal 11
/test_sem_jobqueue/test_sem_jobqueue_2proc_enqueue_dequeue[ ERROR ]
Error: test/test_sem_jobqueue.c:131: assertion failed: sjq != ((void*)0) (0x0 != 0x0)
Error: test/test_sem_jobqueue.c:155: assertion failed: sjq != ((void*)0) (0x0 != 0x0)
Error: child killed by signal 6
/test_sem_jobqueue/test_sem_jobqueue_2proc_peekhead[ ERROR ]
Error: test/test_sem_jobqueue.c:189: assertion failed: sjq != ((void*)0) (0x0 != 0x0)
Error: test/test_sem_jobqueue.c:219: assertion failed: sjq != ((void*)0) (0x0 != 0x0)
Error: child killed by signal 6
/test_sem_jobqueue/test_sem_jobqueue_2proc_peektail[ ERROR ]
Error: test/test_sem_jobqueue.c:274: assertion failed: sjq != ((void*)0) (0x0 != 0x0)
Error: test/test_sem_jobqueue.c:300: assertion failed: sjq != ((void*)0) (0x0 != 0x0)
Error: child killed by signal 6
0 of 11 (0%) tests successful, 0 (0%) test skipped.
------------------------------------------------------
------------------------------------------------------
Running bin/test/test_shobject_name ...
Running test suite with seed 0xe35162aa...
/test_shobject_name/test_shobject_name_short[ ERROR ]
Error: child killed by signal 11
/test_shobject_name/test_shobject_name_empty[ ERROR ]
Error: child killed by signal 11
/test_shobject_name/test_shobject_name_char[ ERROR ]
Error: child killed by signal 11
/test_shobject_name/test_shobject_name_long[ ERROR ]
Error: child killed by signal 11
/test_shobject_name/test_shobject_name_null[ ERROR ]
Error: child killed by signal 11
/test_shobject_name/test_shobject_name_short_heap[ ERROR ]
Error: child killed by signal 11
/test_shobject_name/test_shobject_name_empty_heap[ ERROR ]
Error: child killed by signal 11
/test_shobject_name/test_shobject_name_char_heap[ ERROR ]
Error: child killed by signal 11
/test_shobject_name/test_shobject_name_long_heap[ ERROR ]
Error: child killed by signal 11
/test_shobject_name/test_shobject_name_null_heap[ ERROR ]
Error: child killed by signal 11
0 of 10 (0%) tests successful, 0 (0%) test skipped.
------------------------------------------------------

