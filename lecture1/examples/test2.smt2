(set-option :print-success false)
(set-logic QF_LIA)
(declare-fun x ( ) Int)
(declare-fun y ( ) Int)
(assert (<= (+ x y) 0))
(assert (= x 0))
(assert (or (= x 1) (>= y 0)))
(assert (not (= y 0)))
(check-sat)
(exit)
