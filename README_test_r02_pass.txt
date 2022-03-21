The following is expected test output after correct implementation of all
functions specified in README01.txt and README02.txt.

------------------------------------------------------
Running bin/test/test_ipc ...
Running test suite with seed 0x27cb726a...
/test_ipc/test_ipc                   [ OK    ] [ 1.00103400 / 0.00047200 CPU ]
/test_ipc/test_ipc_err               [ OK    ] [ 0.00000200 / 0.00000100 CPU ]
2 of 2 (100%) tests successful, 0 (0%) test skipped.
------------------------------------------------------
------------------------------------------------------
Running bin/test/test_ipc_jobqueue ...
Running test suite with seed 0xb07e44be...
/test_ipc_jobqueue/test_ipc_jobqueue_capacity[ OK    ] [ 0.00000500 / 0.00000500 CPU ]
/test_ipc_jobqueue/test_ipc_jobqueue_capacity_null[ OK    ] [ 0.00000100 / 0.00000200 CPU ]
/test_ipc_jobqueue/test_ipc_jobqueue_dequeue_fullq[ OK    ] [ 0.00003900 / 0.00003800 CPU ]
/test_ipc_jobqueue/test_ipc_jobqueue_dequeue_inout[ OK    ] [ 0.00005700 / 0.00005700 CPU ]
/test_ipc_jobqueue/test_ipc_jobqueue_dequeue_emptyq[ OK    ] [ 0.00001000 / 0.00001000 CPU ]
/test_ipc_jobqueue/test_ipc_jobqueue_dequeue_heap[ OK    ] [ 0.00004800 / 0.00004800 CPU ]
/test_ipc_jobqueue/test_ipc_jobqueue_dequeue_null[ OK    ] [ 0.00000000 / 0.00000000 CPU ]
/test_ipc_jobqueue/test_ipc_jobqueue_enqueue_tofull[ OK    ] [ 0.00005000 / 0.00004900 CPU ]
/test_ipc_jobqueue/test_ipc_jobqueue_enqueue_inout[ OK    ] [ 0.00006800 / 0.00006900 CPU ]
/test_ipc_jobqueue/test_ipc_jobqueue_enqueue_fullq[ OK    ] [ 0.00002000 / 0.00002000 CPU ]
/test_ipc_jobqueue/test_ipc_jobqueue_enqueue_null[ OK    ] [ 0.00000600 / 0.00000600 CPU ]
/test_ipc_jobqueue/test_ipc_jobqueue_is_empty[ OK    ] [ 0.00000200 / 0.00000200 CPU ]
/test_ipc_jobqueue/test_ipc_jobqueue_is_empty_notempty[ OK    ] [ 0.00001700 / 0.00001700 CPU ]
/test_ipc_jobqueue/test_ipc_jobqueue_is_empty_null[ OK    ] [ 0.00000100 / 0.00000000 CPU ]
/test_ipc_jobqueue/test_ipc_jobqueue_is_full_empty[ OK    ] [ 0.00000100 / 0.00000000 CPU ]
/test_ipc_jobqueue/test_ipc_jobqueue_is_full_filling[ OK    ] [ 0.00001700 / 0.00001800 CPU ]
/test_ipc_jobqueue/test_ipc_jobqueue_is_full_null[ OK    ] [ 0.00000000 / 0.00000000 CPU ]
/test_ipc_jobqueue/test_ipc_jobqueue_peekhead_empty[ OK    ] [ 0.00000100 / 0.00000100 CPU ]
/test_ipc_jobqueue/test_ipc_jobqueue_peekhead_full[ OK    ] [ 0.00008800 / 0.00008800 CPU ]
/test_ipc_jobqueue/test_ipc_jobqueue_peekhead_heap[ OK    ] [ 0.00003600 / 0.00003600 CPU ]
/test_ipc_jobqueue/test_ipc_jobqueue_peekhead_null[ OK    ] [ 0.00000000 / 0.00000100 CPU ]
/test_ipc_jobqueue/test_ipc_jobqueue_peektail_empty[ OK    ] [ 0.00000100 / 0.00000200 CPU ]
/test_ipc_jobqueue/test_ipc_jobqueue_peektail_full[ OK    ] [ 0.00007200 / 0.00007100 CPU ]
/test_ipc_jobqueue/test_ipc_jobqueue_peektail_heap[ OK    ] [ 0.00003000 / 0.00003000 CPU ]
/test_ipc_jobqueue/test_ipc_jobqueue_peektail_wrap[ OK    ] [ 0.00010000 / 0.00010000 CPU ]
/test_ipc_jobqueue/test_ipc_jobqueue_peektail_null[ OK    ] [ 0.00000000 / 0.00000200 CPU ]
26 of 26 (100%) tests successful, 0 (0%) test skipped.
------------------------------------------------------
------------------------------------------------------
Running bin/test/test_job ...
Running test suite with seed 0xb33b2b88...
/test_job/test_job_new               [ OK    ] [ 0.00066600 / 0.00065800 CPU ]
/test_job/test_job_new_null          [ OK    ] [ 0.00005200 / 0.00005100 CPU ]
/test_job/test_job_copy_stack        [ OK    ] [ 0.00033500 / 0.00033600 CPU ]
/test_job/test_job_copy_heap         [ OK    ] [ 0.00033200 / 0.00033200 CPU ]
/test_job/test_job_copy_identity     [ OK    ] [ 0.00063300 / 0.00063200 CPU ]
/test_job/test_job_copy_null         [ OK    ] [ 0.00000100 / 0.00000000 CPU ]
/test_job/test_job_init_stack        [ OK    ] [ 0.00034400 / 0.00034400 CPU ]
/test_job/test_job_init_heap         [ OK    ] [ 0.00042200 / 0.00041700 CPU ]
/test_job/test_job_init_null         [ OK    ] [ 0.00000000 / 0.00000100 CPU ]
/test_job/test_job_is_equal          [ OK    ] [ 0.00065200 / 0.00065200 CPU ]
/test_job/test_job_is_equal_init     [ OK    ] [ 0.00004700 / 0.00004700 CPU ]
/test_job/test_job_is_equal_null     [ OK    ] [ 0.00000200 / 0.00000100 CPU ]
/test_job/test_job_set_stack         [ OK    ] [ 0.00047100 / 0.00047100 CPU ]
/test_job/test_job_set_heap          [ OK    ] [ 0.00048300 / 0.00048400 CPU ]
/test_job/test_job_set_null          [ OK    ] [ 0.00005500 / 0.00005600 CPU ]
15 of 15 (100%) tests successful, 0 (0%) test skipped.
------------------------------------------------------
------------------------------------------------------
Running bin/test/test_joblog ...
Running test suite with seed 0x1bbc8d2d...
/test_joblog/test_joblog_write_entry_cpid0[ OK    ] [ 0.00165800 / 0.00102900 CPU ]
/test_joblog/test_joblog_write_entry_cpid1[ OK    ] [ 0.00074600 / 0.00073100 CPU ]
/test_joblog/test_joblog_write_entry_cpid2[ OK    ] [ 0.00073300 / 0.00071000 CPU ]
/test_joblog/test_joblog_write_entry_cpid3[ OK    ] [ 0.00063600 / 0.00058800 CPU ]
/test_joblog/test_joblog_write_entry_errno[ OK    ] [ 0.00052100 / 0.00052100 CPU ]
/test_joblog/test_joblog_write_entry_null[ OK    ] [ 0.00000200 / 0.00000200 CPU ]
/test_joblog/test_joblog_read_entry_cpid0[ OK    ] [ 0.00037600 / 0.00037700 CPU ]
/test_joblog/test_joblog_read_entry_cpid1[ OK    ] [ 0.00031200 / 0.00031200 CPU ]
/test_joblog/test_joblog_read_entry_cpid2[ OK    ] [ 0.00033200 / 0.00033200 CPU ]
/test_joblog/test_joblog_read_entry_cpid3[ OK    ] [ 0.00034700 / 0.00033800 CPU ]
/test_joblog/test_joblog_read_entry_stack[ OK    ] [ 0.00028900 / 0.00028800 CPU ]
/test_joblog/test_joblog_read_entry_rand[ OK    ] [ 0.00043400 / 0.00043400 CPU ]
/test_joblog/test_joblog_read_entry_bounds[ OK    ] [ 0.00015500 / 0.00015100 CPU ]
/test_joblog/test_joblog_read_entry_null[ OK    ] [ 0.00000900 / 0.00001000 CPU ]
/test_joblog/test_joblog_read_entry_errno[ OK    ] [ 0.00026800 / 0.00026200 CPU ]
/test_joblog/test_joblog_delete      [ OK    ] [ 0.00032800 / 0.00032700 CPU ]
16 of 16 (100%) tests successful, 0 (0%) test skipped.
------------------------------------------------------
------------------------------------------------------
Running bin/test/test_jobqueue ...
Running test suite with seed 0x59b8f02b...
/test_jobqueue/test_jobqueue_new     [ OK    ] [ 0.00001400 / 0.00001200 CPU ]
/test_jobqueue/test_jobqueue_capacity[ OK    ] [ 0.00000200 / 0.00000200 CPU ]
/test_jobqueue/test_jobqueue_capacity_null[ OK    ] [ 0.00000000 / 0.00000000 CPU ]
/test_jobqueue/test_jobqueue_dequeue_fullq[ OK    ] [ 0.00003400 / 0.00003400 CPU ]
/test_jobqueue/test_jobqueue_dequeue_inout[ OK    ] [ 0.00004300 / 0.00004400 CPU ]
/test_jobqueue/test_jobqueue_dequeue_emptyq[ OK    ] [ 0.00001400 / 0.00001300 CPU ]
/test_jobqueue/test_jobqueue_dequeue_heap[ OK    ] [ 0.00007300 / 0.00007400 CPU ]
/test_jobqueue/test_jobqueue_dequeue_null[ OK    ] [ 0.00000200 / 0.00000100 CPU ]
/test_jobqueue/test_jobqueue_enqueue_tofull[ OK    ] [ 0.00006700 / 0.00006700 CPU ]
/test_jobqueue/test_jobqueue_enqueue_inout[ OK    ] [ 0.00009300 / 0.00009400 CPU ]
/test_jobqueue/test_jobqueue_enqueue_fullq[ OK    ] [ 0.00002600 / 0.00002500 CPU ]
/test_jobqueue/test_jobqueue_enqueue_null[ OK    ] [ 0.00000400 / 0.00000400 CPU ]
/test_jobqueue/test_jobqueue_is_empty[ OK    ] [ 0.00000100 / 0.00000100 CPU ]
/test_jobqueue/test_jobqueue_is_empty_notempty[ OK    ] [ 0.00001500 / 0.00001500 CPU ]
/test_jobqueue/test_jobqueue_is_empty_null[ OK    ] [ 0.00000000 / 0.00000200 CPU ]
/test_jobqueue/test_jobqueue_is_full_empty[ OK    ] [ 0.00000100 / 0.00000000 CPU ]
/test_jobqueue/test_jobqueue_is_full_filling[ OK    ] [ 0.00002100 / 0.00002300 CPU ]
/test_jobqueue/test_jobqueue_is_full_null[ OK    ] [ 0.00000100 / 0.00000000 CPU ]
/test_jobqueue/test_jobqueue_peekhead_empty[ OK    ] [ 0.00000100 / 0.00000000 CPU ]
/test_jobqueue/test_jobqueue_peekhead_full[ OK    ] [ 0.00010900 / 0.00011000 CPU ]
/test_jobqueue/test_jobqueue_peekhead_heap[ OK    ] [ 0.00005100 / 0.00005100 CPU ]
/test_jobqueue/test_jobqueue_peekhead_null[ OK    ] [ 0.00000000 / 0.00000000 CPU ]
/test_jobqueue/test_jobqueue_peektail_empty[ OK    ] [ 0.00000000 / 0.00000100 CPU ]
/test_jobqueue/test_jobqueue_peektail_full[ OK    ] [ 0.00006900 / 0.00006800 CPU ]
/test_jobqueue/test_jobqueue_peektail_heap[ OK    ] [ 0.00003700 / 0.00003700 CPU ]
/test_jobqueue/test_jobqueue_peektail_wrap[ OK    ] [ 0.00012500 / 0.00012400 CPU ]
/test_jobqueue/test_jobqueue_peektail_null[ OK    ] [ 0.00000100 / 0.00000100 CPU ]
/test_jobqueue/test_jobqueue_delete  [ OK    ] [ 0.00000100 / 0.00000200 CPU ]
28 of 28 (100%) tests successful, 0 (0%) test skipped.
------------------------------------------------------
------------------------------------------------------
Running bin/test/test_mutex_lockvar ...
Running test suite with seed 0x923a8e30...
/test_mutex_lockvar/test_mutex_new   [ OK    ] [ 1.00091600 / 0.00022900 CPU ]
/test_mutex_lockvar/test_mutex_new_null[ OK    ] [ 0.00000600 / 0.00000600 CPU ]
/test_mutex_lockvar/test_mutex_enter [ OK    ] [ 1.00121000 / 0.00019600 CPU ]
/test_mutex_lockvar/test_mutex_enter_null[ OK    ] [ 0.00000300 / 0.00000400 CPU ]
/test_mutex_lockvar/test_mutex_leave [ OK    ] [ 0.00000600 / 0.00000600 CPU ]
/test_mutex_lockvar/test_mutex_leave_null[ OK    ] [ 0.00000300 / 0.00000300 CPU ]
6 of 6 (100%) tests successful, 0 (0%) test skipped.
------------------------------------------------------
------------------------------------------------------
Running bin/test/test_mutex_noop ...
Running test suite with seed 0xa9b5b697...
/test_mutex_noop/test_mutex_new      [ OK    ] [ 0.00000600 / 0.00000500 CPU ]
/test_mutex_noop/test_mutex_new_null [ OK    ] [ 0.00000000 / 0.00000000 CPU ]
/test_mutex_noop/test_mutex_enter    [ OK    ] [ 0.00000500 / 0.00000500 CPU ]
/test_mutex_noop/test_mutex_enter_null[ OK    ] [ 0.00000100 / 0.00000100 CPU ]
/test_mutex_noop/test_mutex_leave    [ OK    ] [ 0.00000100 / 0.00000100 CPU ]
/test_mutex_noop/test_mutex_leave_null[ OK    ] [ 0.00000200 / 0.00000200 CPU ]
6 of 6 (100%) tests successful, 0 (0%) test skipped.
------------------------------------------------------
------------------------------------------------------
Running bin/test/test_mutex_peterson ...
Running test suite with seed 0xf1a7de14...
/test_mutex_peterson/test_mutex_new  [ OK    ] [ 2.00191700 / 0.00049100 CPU ]
/test_mutex_peterson/test_mutex_new_null[ OK    ] [ 0.00000600 / 0.00000600 CPU ]
/test_mutex_peterson/test_mutex_enter_01[ OK    ] [ 1.00091000 / 0.00031300 CPU ]
/test_mutex_peterson/test_mutex_enter_02[ OK    ] [ 1.00333300 / 0.00017900 CPU ]
/test_mutex_peterson/test_mutex_enter_null[ OK    ] [ 0.00000400 / 0.00000400 CPU ]
/test_mutex_peterson/test_mutex_leave_01[ OK    ] [ 1.00119400 / 0.00016300 CPU ]
/test_mutex_peterson/test_mutex_leave_02[ OK    ] [ 1.00080300 / 0.00016100 CPU ]
/test_mutex_peterson/test_mutex_leave_null[ OK    ] [ 0.00000700 / 0.00000700 CPU ]
8 of 8 (100%) tests successful, 0 (0%) test skipped.
------------------------------------------------------
------------------------------------------------------
Running bin/test/test_proc ...
Running test suite with seed 0xf12a7fa0...
/test_util/test_proc_new             [ OK    ] [ 0.00000800 / 0.00000800 CPU ]
/test_util/test_proc_new_null        [ OK    ] [ 0.00000300 / 0.00000300 CPU ]
2 of 2 (100%) tests successful, 0 (0%) test skipped.
------------------------------------------------------
------------------------------------------------------
Running bin/test/test_sem_jobqueue ...
Running test suite with seed 0xdda29773...
/test_sem_jobqueue/test_sem_jobqueue_capacity[ OK    ] [ 0.00000800 / 0.00000700 CPU ]
/test_sem_jobqueue/test_sem_jobqueue_capacity_null[ OK    ] [ 0.00000200 / 0.00000300 CPU ]
/test_sem_jobqueue/test_sem_jobqueue_dequeue_null[ OK    ] [ 0.00000300 / 0.00000200 CPU ]
/test_sem_jobqueue/test_sem_jobqueue_enqueue_null[ OK    ] [ 0.00001500 / 0.00001600 CPU ]
/test_sem_jobqueue/test_sem_jobqueue_is_empty_null[ OK    ] [ 0.00000300 / 0.00000200 CPU ]
/test_sem_jobqueue/test_sem_jobqueue_is_full_null[ OK    ] [ 0.00000500 / 0.00000300 CPU ]
/test_sem_jobqueue/test_sem_jobqueue_peekhead_null[ OK    ] [ 0.00000300 / 0.00000300 CPU ]
/test_sem_jobqueue/test_sem_jobqueue_peektail_null[ OK    ] [ 0.00000400 / 0.00000400 CPU ]
/test_sem_jobqueue/test_sem_jobqueue_2proc_enqueue_dequeue[ OK    ] [ 1.00727900 / 0.00343500 CPU ]
/test_sem_jobqueue/test_sem_jobqueue_2proc_peekhead...............................................................................................................................
[ OK    ] [ 6.95993900 / 0.01378300 CPU ]
/test_sem_jobqueue/test_sem_jobqueue_2proc_peektail...............................................................................................................................
[ OK    ] [ 2.65378900 / 0.00120200 CPU ]
11 of 11 (100%) tests successful, 0 (0%) test skipped.
------------------------------------------------------
------------------------------------------------------
Running bin/test/test_shobject_name ...
Running test suite with seed 0xb15fc5cc...
/test_shobject_name/test_shobject_name_short[ OK    ] [ 0.00000700 / 0.00000700 CPU ]
/test_shobject_name/test_shobject_name_empty[ OK    ] [ 0.00000200 / 0.00000300 CPU ]
/test_shobject_name/test_shobject_name_char[ OK    ] [ 0.00000200 / 0.00000200 CPU ]
/test_shobject_name/test_shobject_name_long[ OK    ] [ 0.00000200 / 0.00000100 CPU ]
/test_shobject_name/test_shobject_name_null[ OK    ] [ 0.00000200 / 0.00000200 CPU ]
/test_shobject_name/test_shobject_name_short_heap[ OK    ] [ 0.00000300 / 0.00000300 CPU ]
/test_shobject_name/test_shobject_name_empty_heap[ OK    ] [ 0.00000300 / 0.00000300 CPU ]
/test_shobject_name/test_shobject_name_char_heap[ OK    ] [ 0.00000300 / 0.00000200 CPU ]
/test_shobject_name/test_shobject_name_long_heap[ OK    ] [ 0.00000300 / 0.00000300 CPU ]
/test_shobject_name/test_shobject_name_null_heap[ OK    ] [ 0.00000200 / 0.00000300 CPU ]
10 of 10 (100%) tests successful, 0 (0%) test skipped.
------------------------------------------------------


